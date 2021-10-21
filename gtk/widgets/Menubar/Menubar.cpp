#include "Menubar.h"

Menubar::Menubar(): Gtk::Box() {}

void Menubar::createFileMenuButton(EventValueChanged *eventValueChanged) {
    this->fileMenuButton = new FileMenuButton(eventValueChanged);
    this->add(*fileMenuButton);
}
