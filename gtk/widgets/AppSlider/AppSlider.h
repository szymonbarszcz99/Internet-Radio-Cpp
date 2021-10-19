#ifndef UNTITLED2_APPSLIDER_H
#define UNTITLED2_APPSLIDER_H
#include <gtkmm/scale.h>
#include <gtkmm/box.h>
#include <gtkmm/image.h>
#include "../AppWidget/AppWidget.h"
#include "../Buttons/Events/EventValueChanged.h"

class AppSlider{
    Gtk::Box appWidget;
    Gtk::Image image;
    Gtk::Scale slider;
    EventValueChanged* properEvent;
    Actions action = SLIDER;
    void pack();

public:
    AppSlider(EventValueChanged* properEvent, Actions action = SLIDER);
    void style(std::string styleString);
    void onClicked();
    Gtk::Box* getBox();
    Gtk::Widget* getAppWidget();
};


#endif //UNTITLED2_APPSLIDER_H
