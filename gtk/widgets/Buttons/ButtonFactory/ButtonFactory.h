#ifndef UNTITLED2_BUTTONFACTORY_H
#define UNTITLED2_BUTTONFACTORY_H
#include <gtkmm/button.h>
#include "../Events/Event.h"

class ButtonFactory : public Gtk::Button {
    Event* eventClicked = nullptr;
    Actions action;
public:
    ButtonFactory(const char* icon, Event* eventClicked, Actions action);
    void onClicked();
};


#endif //UNTITLED2_BUTTONFACTORY_H
