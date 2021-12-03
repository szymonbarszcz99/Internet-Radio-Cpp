#ifndef UNTITLED2_APPBUTTON_H
#define UNTITLED2_APPBUTTON_H
#include <gtkmm/button.h>
#include "../Events/Event.h"
#include <memory>

class AppButton : public Gtk::Button{
    const Event& properEvent;
    Actions action;
    void onClicked();
public:
    AppButton(const Event& properEvent, Actions action);
    ~AppButton() override{
        std::cout<<"App Button destructor"<<std::endl;
    }
};


#endif //UNTITLED2_APPBUTTON_H
