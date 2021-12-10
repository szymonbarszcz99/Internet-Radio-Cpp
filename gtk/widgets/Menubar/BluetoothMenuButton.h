#ifndef UNTITLED2_BLUETOOTHMENUBUTTON_H
#define UNTITLED2_BLUETOOTHMENUBUTTON_H
#pragma once
#include <gtkmm/menu.h>
#include <gtkmm/menuitem.h>
#include "../Events/Event.h"


class BluetoothMenuButton : public Gtk::MenuItem{
    const Event& eventValueChanged;
    std::unique_ptr<Gtk::Menu> BluetoothMenu;
    void onValueChosen(Actions actionId);
    std::array<Gtk::MenuItem,2> optionsVector;
public:
    BluetoothMenuButton(const Event& eventValueChanged);
    ~BluetoothMenuButton() override{
        std::cout<<"BluetoothMenuButton destructor"<<std::endl;
    }
};


#endif //UNTITLED2_BLUETOOTHMENUBUTTON_H
