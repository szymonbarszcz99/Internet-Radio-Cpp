#ifndef UNTITLED2_APPBUTTON_H
#define UNTITLED2_APPBUTTON_H
#include <gtkmm/button.h>
#include "../Events/Event.h"
#include <memory>

class AppButton : public Gtk::Button{
    std::shared_ptr<Event> properEvent;
    Actions action;
    void onClicked();
public:
    AppButton(std::shared_ptr<Event> properEvent, Actions action);
};


#endif //UNTITLED2_APPBUTTON_H
