#ifndef UNTITLED2_APPBUTTON_H
#define UNTITLED2_APPBUTTON_H
#include <gtkmm/button.h>
#include "../Events/Event.h"

class AppButton : public Gtk::Button{
    Event* properEvent;
    Actions action;
    void onClicked();
public:
    AppButton(Event *properEvent, Actions action);
};


#endif //UNTITLED2_APPBUTTON_H
