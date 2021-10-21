#ifndef UNTITLED2_FILEMENUBUTTON_H
#define UNTITLED2_FILEMENUBUTTON_H
#include <gtkmm/menu.h>
#include <gtkmm/menubutton.h>
#include "../Buttons/Events/EventValueChanged.h"

class FileMenuButton : public Gtk::MenuButton{
    EventValueChanged* eventValueChanged;
    void onValueChosen(int valueId);
    Gtk::Menu* fileMenu;
public:
    FileMenuButton(EventValueChanged* eventValueChanged);
};


#endif //UNTITLED2_FILEMENUBUTTON_H
