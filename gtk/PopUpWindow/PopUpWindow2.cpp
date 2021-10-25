#include "PopUpWindow2.h"

void PopUpWindow2::populate() {
    Gtk::Label* name = new Gtk::Label("Name");

    this->grid->attach(*name,0,0);
    this->grid->attach(*nameEntry,0,1);

    Gtk::Label* link = new Gtk::Label("Link");

    this->grid->attach(*link,0,2);
    this->grid->attach(*linkEntry,0,3);

    this->grid->attach(*addButton, 0,4);
}

void PopUpWindow2::onAddClicked() {
    this->event->eventPassArg(std::string(nameEntry->get_text()), std::string(linkEntry->get_text()),windowPurpose);
}
