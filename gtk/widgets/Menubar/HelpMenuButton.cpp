#include "HelpMenuButton.h"

HelpMenuButton::HelpMenuButton(const Event &eventValueChanged):
eventValueChanged(eventValueChanged), Gtk::MenuItem("Help") {

    this->HelpMenu = std::make_unique<Gtk::Menu>();

    this->optionsVector[0] = Gtk::MenuItem("Get stations from TuneIn");
    this->optionsVector[0].signal_activate().connect(sigc::bind<Actions>(sigc::mem_fun(*this,&HelpMenuButton::onValueChosen),HELP_TUNEIN));
    this->optionsVector[1] = Gtk::MenuItem("Make your stations.csv file");
    this->optionsVector[1].signal_activate().connect(sigc::bind<Actions>(sigc::mem_fun(*this,&HelpMenuButton::onValueChosen),HELP_FILE));

    this->HelpMenu->append(this->optionsVector[0]);
    this->HelpMenu->append(this->optionsVector[1]);

    this->set_submenu(*HelpMenu);
    this->show_all();
}

void HelpMenuButton::onValueChosen(Actions actionId) {
    eventValueChanged.eventPassArg(actionId);
}
