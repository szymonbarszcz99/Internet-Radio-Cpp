#include "Menubar.h"

Menubar::Menubar(Event* event): Gtk::MenuBar() {
    this->createFileMenuButton(event);
    this->createViewStationButton(event);

}

void Menubar::createFileMenuButton(Event *eventValueChanged) {
    this->fileMenuButton = new FileMenuButton(eventValueChanged);
    this->add(*fileMenuButton);
}

void Menubar::createViewStationButton(Event * event) {
    this->viewStationsButton = new ViewStationsButton(event);
    this->add(*viewStationsButton);
}
