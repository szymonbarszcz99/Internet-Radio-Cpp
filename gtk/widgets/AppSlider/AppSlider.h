#ifndef UNTITLED2_APPSLIDER_H
#define UNTITLED2_APPSLIDER_H
#pragma once
#include <gtkmm/scale.h>
#include <gtkmm/box.h>
#include <gtkmm/image.h>
#include <iostream>
#include <memory>
#include "../Events/Event.h"

class AppSlider: public Gtk::Box{
    Gtk::Image image;
    Gtk::Scale slider;
    const Event& properEvent;
    void pack();
    void onClicked();
    AppSlider* createImage();
    AppSlider* createSlider();

public:
    explicit AppSlider(const Event& properEvent);
    ~AppSlider() override{
        std::cout<<"App Slider destructor"<<std::endl;
    }
};


#endif //UNTITLED2_APPSLIDER_H
