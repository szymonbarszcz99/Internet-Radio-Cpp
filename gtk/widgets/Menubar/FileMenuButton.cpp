#include "FileMenuButton.h"

FileMenuButton::FileMenuButton(Event *eventValueChanged): eventValueChanged(eventValueChanged), Gtk::MenuItem("File"){

    this->fileMenu = new Gtk::Menu();
    auto addStation = new Gtk::MenuItem("Add Station");
    auto deleteStation = new Gtk::MenuItem("Delete Station");
    auto editStation = new Gtk::MenuItem("Edit current station");
    addStation->signal_activate().connect(sigc::bind<int>(sigc::mem_fun(*this,&FileMenuButton::onValueChosen),1));
    deleteStation->signal_activate().connect(sigc::bind<int>(sigc::mem_fun(*this,&FileMenuButton::onValueChosen),2));
    editStation->signal_activate().connect(sigc::bind<int>(sigc::mem_fun(*this,&FileMenuButton::onValueChosen),3));
    fileMenu->append(*addStation);
    fileMenu->append(*deleteStation);
    fileMenu->append(*editStation);


    this->set_submenu(*fileMenu);this->fileMenu->show_all();
}

void FileMenuButton::onValueChosen(int valueId) {
    this->eventValueChanged->eventPassArg(valueId);
}
