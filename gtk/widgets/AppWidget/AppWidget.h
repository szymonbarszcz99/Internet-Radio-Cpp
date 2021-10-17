#ifndef UNTITLED2_APPWIDGET_H
#define UNTITLED2_APPWIDGET_H
#include <string>
#include <gtkmm/widget.h>
#include "../Buttons/Events/Event.h"

class AppWidget : public Gtk::Widget{
public:
    virtual void style(std::string styleString)=0;
    virtual void onClicked()=0;
    virtual Gtk::Widget* getAppWidget()=0;
    virtual ~AppWidget(){};
};


#endif //UNTITLED2_APPWIDGET_H
