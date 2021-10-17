#ifndef UNTITLED2_APPBUTTON_H
#define UNTITLED2_APPBUTTON_H
#include <gtkmm/button.h>
#include "../AppWidget/AppWidget.h"

class AppButton : public AppWidget{
    Event* properEvent;
    Gtk::Button appWidget;
public:
    void style(std::string styleString) override;
    void onClicked() override;
    AppButton(Event *properEvent);
    Gtk::Widget* getAppWidget() override;
};


#endif //UNTITLED2_APPBUTTON_H
