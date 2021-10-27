#ifndef UNTITLED2_VIEWSTATIONSBUTTON_H
#define UNTITLED2_VIEWSTATIONSBUTTON_H
#include <gtkmm/menu.h>
#include <gtkmm/menubutton.h>
#include "../Events/Event.h"

class ViewStationsButton : public Gtk::MenuItem{
Event* properEvent;
Gtk::Menu* viewMenu;
void onValueChosen(Actions actionId);
public:
    ViewStationsButton(Event* properEvent);
};


#endif //UNTITLED2_VIEWSTATIONSBUTTON_H
