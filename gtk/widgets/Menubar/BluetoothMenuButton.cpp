#include "BluetoothMenuButton.h"

BluetoothMenuButton::BluetoothMenuButton(const Event &eventValueChanged):
        eventValueChanged(eventValueChanged), Gtk::MenuItem("Bluetooth") {

    this->BluetoothMenu = std::make_unique<Gtk::Menu>();

    this->BluetoothMenu = std::make_unique<Gtk::Menu>();
    this->optionsVector[0] = Gtk::MenuItem("Find devices");
    this->optionsVector[0].signal_activate().connect(sigc::bind<Actions>(sigc::mem_fun(*this,&BluetoothMenuButton::onValueChosen),BT_SCAN));
    this->BluetoothMenu->append(this->optionsVector[0]);

    this->set_submenu(*BluetoothMenu);
    this->show_all();
}

void BluetoothMenuButton::onValueChosen(Actions actionId) {
    this->eventValueChanged.eventPassArg(actionId);
}
