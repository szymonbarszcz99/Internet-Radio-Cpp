#ifndef UNTITLED2_APPSLIDER_H
#define UNTITLED2_APPSLIDER_H
#include <gtkmm/scale.h>
#include <gtkmm/box.h>
#include <gtkmm/image.h>
#include "../Events/Event.h"

class AppSlider: public Gtk::Box{
    Gtk::Image image;
    Gtk::Scale slider;
    Event* properEvent;
    void pack();
    void onClicked();
    AppSlider* createImage();
    AppSlider* createSlider();

public:
    AppSlider(Event* properEvent);
};


#endif //UNTITLED2_APPSLIDER_H
