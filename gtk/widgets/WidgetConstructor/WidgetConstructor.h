#ifndef UNTITLED2_WIDGETCONSTRUCTOR_H
#define UNTITLED2_WIDGETCONSTRUCTOR_H
#include <gtkmm/widget.h>
#include "../AppWidget/AppWidget.h"

class WidgetConstructor : public Gtk::Widget{
public:
    virtual ~WidgetConstructor(){}
    virtual AppWidget* FactoryMethod(Event* properEvent, Actions action)=0;
    void applyMargin();
};


#endif //UNTITLED2_WIDGETCONSTRUCTOR_H
