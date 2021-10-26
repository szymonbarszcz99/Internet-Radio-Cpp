#include "AppSlider.h"

AppSlider::AppSlider(Event* properEvent): properEvent(properEvent), Gtk::Box(){

    //Box
    this->property_margin() = 10;

    createImage()->createSlider()->pack();
}

void AppSlider::pack() {
    this->pack_start(this->image, false, false);
    this->pack_end(this->slider,true,true);
}

void AppSlider::onClicked() {
    this->properEvent->eventPassArg(this->slider.get_value());
}


AppSlider *AppSlider::createImage() {
    this->image = Gtk::Image();
    this->image.set_from_icon_name("audio-volume-high",Gtk::IconSize(GTK_ICON_SIZE_LARGE_TOOLBAR));

    return this;
}

AppSlider *AppSlider::createSlider() {
    this->slider = Gtk::Scale();
    this->slider.set_digits(0);
    this->slider.set_range(0,100);
    this->slider.signal_value_changed().connect(sigc::mem_fun(*this,&AppSlider::onClicked));
    this->slider.set_value(50);

    return this;
}
