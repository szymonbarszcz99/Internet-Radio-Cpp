#ifndef UNTITLED2_APPSLIDER_H
#define UNTITLED2_APPSLIDER_H
#include <gtkmm/scale.h>
#include <gtkmm/box.h>
#include <gtkmm/image.h>
#include "../AppWidget/AppWidget.h"
#include "../Buttons/Events/EventValueChanged.h"

class AppSlider: public AppWidget{
    Gtk::Box appWidget;
    Gtk::Image image;
    Gtk::Scale slider;
    EventValueChanged* properEvent;
    void pack();

public:
    AppSlider(EventValueChanged* properEvent);
    void style(std::string styleString);
    void onClicked();
    Gtk::Widget* getAppWidget();
};


#endif //UNTITLED2_APPSLIDER_H
