#include "FileMenuButton.h"

FileMenuButton::FileMenuButton(std::shared_ptr<Event> eventValueChanged): eventValueChanged(eventValueChanged), Gtk::MenuItem("File"){

    this->fileMenu = std::make_unique<Gtk::Menu>();
    optionsVector.emplace_back(std::make_unique<Gtk::MenuItem>("Add Station"));
    optionsVector.emplace_back(std::make_unique<Gtk::MenuItem>("Delete Station"));
    optionsVector.emplace_back(std::make_unique<Gtk::MenuItem>("Edit current"));
    optionsVector[0]->signal_activate().connect(sigc::bind<Actions>(sigc::mem_fun(*this,&FileMenuButton::onValueChosen),ADD_STATION));
    optionsVector[1]->signal_activate().connect(sigc::bind<Actions>(sigc::mem_fun(*this,&FileMenuButton::onValueChosen),DELETE_STATION));
    optionsVector[2]->signal_activate().connect(sigc::bind<Actions>(sigc::mem_fun(*this,&FileMenuButton::onValueChosen),MODIFY_STATION));
    fileMenu->append(*optionsVector[0]);
    fileMenu->append(*optionsVector[1]);
    fileMenu->append(*optionsVector[2]);

    this->set_submenu(*fileMenu);
    this->fileMenu->show_all();
}

void FileMenuButton::onValueChosen(Actions actionId) {
    this->eventValueChanged->eventPassArg(actionId);
}
