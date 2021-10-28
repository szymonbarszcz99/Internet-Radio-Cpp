#include "ViewStationsButton.h"

ViewStationsButton::ViewStationsButton(std::shared_ptr<Event> properEvent): properEvent(properEvent), Gtk::MenuItem("View") {
    this->viewMenu = std::make_unique<Gtk::Menu>();
    this->menuItem = std::make_unique<Gtk::MenuItem>("Stations");
    this->menuItem->signal_activate().connect(sigc::bind<Actions>(sigc::mem_fun(*this,&ViewStationsButton::onValueChosen),VIEW));
    viewMenu->append(*menuItem);

    this->set_submenu(*viewMenu);
}

void ViewStationsButton::onValueChosen(Actions actionId) {
    this->properEvent->eventPassArg(actionId);
}
