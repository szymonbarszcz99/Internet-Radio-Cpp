#include "FileMenuButton.h"

FileMenuButton::FileMenuButton(Event *eventValueChanged): eventValueChanged(eventValueChanged), Gtk::MenuItem("File"){

    this->fileMenu = new Gtk::Menu();
    auto addStation = new Gtk::MenuItem("Add Station");
    auto deleteStation = new Gtk::MenuItem("Delete Station");
    auto editStation = new Gtk::MenuItem("Edit current station");
    addStation->signal_activate().connect(sigc::bind<Actions>(sigc::mem_fun(*this,&FileMenuButton::onValueChosen),ADD_STATION));
    deleteStation->signal_activate().connect(sigc::bind<Actions>(sigc::mem_fun(*this,&FileMenuButton::onValueChosen),DELETE_STATION));
    editStation->signal_activate().connect(sigc::bind<Actions>(sigc::mem_fun(*this,&FileMenuButton::onValueChosen),MODIFY_STATION));
    fileMenu->append(*addStation);
    fileMenu->append(*deleteStation);
    fileMenu->append(*editStation);


    this->set_submenu(*fileMenu);this->fileMenu->show_all();
}

void FileMenuButton::onValueChosen(Actions actionId) {
    this->eventValueChanged->eventPassArg(actionId);
}
