#include "ViewStationsButton.h"

ViewStationsButton::ViewStationsButton(Event *properEvent): properEvent(properEvent), Gtk::MenuItem("View") {
    this->viewMenu = new Gtk::Menu();
    auto viewStations = new Gtk::MenuItem("Stations");
    viewStations->signal_activate().connect(sigc::bind<Actions>(sigc::mem_fun(*this,&ViewStationsButton::onValueChosen),VIEW));
    viewMenu->append(*viewStations);

    this->set_submenu(*viewMenu);
}

void ViewStationsButton::onValueChosen(Actions actionId) {
    this->properEvent->eventPassArg(actionId);
}
