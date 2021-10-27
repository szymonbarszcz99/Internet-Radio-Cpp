#ifndef UNTITLED2_FILEMENUBUTTON_H
#define UNTITLED2_FILEMENUBUTTON_H
#include <gtkmm/menu.h>
#include <gtkmm/menubutton.h>
#include "../Events/Event.h"

class FileMenuButton : public Gtk::MenuItem{
    Event* eventValueChanged;
    void onValueChosen(Actions actionId);
    Gtk::Menu* fileMenu;
public:
    FileMenuButton(Event* eventValueChanged);
};


#endif //UNTITLED2_FILEMENUBUTTON_H
