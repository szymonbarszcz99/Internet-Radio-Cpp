#include "Menubar.h"

Menubar::Menubar(const Event& event): Gtk::MenuBar() {
    this->property_hexpand() = true;

    this->fileMenuButton = std::make_unique<FileMenuButton>(event);
    this->add(*fileMenuButton);

    this->helpMenuButton = std::make_unique<HelpMenuButton>(event);
    this->add(*helpMenuButton);

    this->bluetoothMenuButton = std::make_unique<BluetoothMenuButton>(event);
    this->add(*bluetoothMenuButton);
}


