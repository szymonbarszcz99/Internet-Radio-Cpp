#include "BluetoothMenuButton.h"

BluetoothMenuButton::BluetoothMenuButton(const Event &eventValueChanged):
        eventValueChanged(eventValueChanged), Gtk::MenuItem("Bluetooth") {

    this->BluetoothMenu = std::make_unique<Gtk::Menu>();

    this->BluetoothMenu = std::make_unique<Gtk::Menu>();
    this->optionsVector[0] = Gtk::MenuItem("Find devices");
    this->BluetoothMenu->append(this->optionsVector[0]);

    this->set_submenu(*BluetoothMenu);
    this->show_all();
}
