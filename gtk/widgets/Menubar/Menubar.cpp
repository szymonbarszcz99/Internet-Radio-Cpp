#include "Menubar.h"

Menubar::Menubar(std::shared_ptr<Event> event): Gtk::MenuBar() {
    this->createFileMenuButton(event);
    this->createViewStationButton(event);

}

void Menubar::createFileMenuButton(std::shared_ptr<Event>eventValueChanged) {
    this->fileMenuButton = std::make_unique<FileMenuButton>(eventValueChanged);
    this->add(*fileMenuButton);
}

void Menubar::createViewStationButton(std::shared_ptr<Event> event) {
    this->viewStationsButton = std::make_unique<ViewStationsButton>(event);
    this->add(*viewStationsButton);
}
