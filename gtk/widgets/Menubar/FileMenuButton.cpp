#include "FileMenuButton.h"

FileMenuButton::FileMenuButton(const Event& eventValueChanged): eventValueChanged(eventValueChanged), Gtk::MenuItem("Stations"){

    this->fileMenu = std::make_unique<Gtk::Menu>();
    optionsVector[0] = Gtk::MenuItem("Add Station");
    optionsVector[1] = Gtk::MenuItem("Delete Station");
    optionsVector[2] = Gtk::MenuItem("Edit current");
    optionsVector[3] = Gtk::MenuItem("View all");
    optionsVector[0].signal_activate().connect(sigc::bind<Actions>(sigc::mem_fun(*this,&FileMenuButton::onValueChosen),ADD_STATION));
    optionsVector[1].signal_activate().connect(sigc::bind<Actions>(sigc::mem_fun(*this,&FileMenuButton::onValueChosen),DELETE_STATION));
    optionsVector[2].signal_activate().connect(sigc::bind<Actions>(sigc::mem_fun(*this,&FileMenuButton::onValueChosen),MODIFY_STATION));
    optionsVector[3].signal_activate().connect(sigc::bind<Actions>(sigc::mem_fun(*this,&FileMenuButton::onValueChosen),VIEW_ALL));
    fileMenu->append(optionsVector[0]);
    fileMenu->append(optionsVector[1]);
    fileMenu->append(optionsVector[2]);
    fileMenu->append(optionsVector[3]);

    this->set_submenu(*fileMenu);
    this->fileMenu->show_all();
}

void FileMenuButton::onValueChosen(Actions actionId) {
    this->eventValueChanged.eventPassArg(actionId);
}
