#ifndef UNTITLED2_FILEMENUBUTTON_H
#define UNTITLED2_FILEMENUBUTTON_H
#pragma once
#include <gtkmm/menu.h>
#include <gtkmm/menubutton.h>
#include "../Events/Event.h"

class FileMenuButton : public Gtk::MenuItem{
    const Event& eventValueChanged;
    void onValueChosen(Actions actionId);
    std::unique_ptr<Gtk::Menu> fileMenu;
    std::array<Gtk::MenuItem,4> optionsVector;
public:
    FileMenuButton(const Event& eventValueChanged);
    ~FileMenuButton() override{
        std::cout<<"FileMenuButton destructor"<<std::endl;
    }
};


#endif //UNTITLED2_FILEMENUBUTTON_H
