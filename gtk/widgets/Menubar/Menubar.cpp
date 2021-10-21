#include "Menubar.h"

Menubar::Menubar(): Gtk::MenuBar() {}

void Menubar::createFileMenuButton(Event *eventValueChanged) {
    this->fileMenuButton = new FileMenuButton(eventValueChanged);
    this->add(*fileMenuButton);
}

void Menubar::createViewStationButton(Event * event) {
    this->viewStationsButton = new ViewStationsButton(event);
    this->add(*viewStationsButton);
}
