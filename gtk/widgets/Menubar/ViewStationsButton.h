#ifndef UNTITLED2_VIEWSTATIONSBUTTON_H
#define UNTITLED2_VIEWSTATIONSBUTTON_H
#include <gtkmm/menu.h>
#include <gtkmm/menubutton.h>
#include "../Buttons/Events/Event.h"

class ViewStationsButton : public Gtk::MenuItem{
Event* properEvent;
Gtk::Menu* viewMenu;
void onValueChosen(int valueId);
public:
    ViewStationsButton(Event* properEvent);
};


#endif //UNTITLED2_VIEWSTATIONSBUTTON_H
