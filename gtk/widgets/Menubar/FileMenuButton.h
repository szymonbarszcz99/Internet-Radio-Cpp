#ifndef UNTITLED2_FILEMENUBUTTON_H
#define UNTITLED2_FILEMENUBUTTON_H
#include <gtkmm/menu.h>
#include <gtkmm/menubutton.h>
#include "../Buttons/Events/Event.h"

class FileMenuButton : public Gtk::MenuButton{
    Event* eventValueChanged;
    void onValueChosen(int valueId);
    Gtk::Menu* fileMenu;
public:
    FileMenuButton(Event* eventValueChanged);
};


#endif //UNTITLED2_FILEMENUBUTTON_H
