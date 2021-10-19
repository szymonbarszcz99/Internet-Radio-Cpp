#include "AppSlider.h"

AppSlider::AppSlider(EventValueChanged* properEvent, Actions action): properEvent(properEvent), action(action){
    //Slider
    this->slider = Gtk::Scale();
    this->slider.set_digits(0);
    this->slider.set_range(0,100);
    this->slider.signal_value_changed().connect(sigc::mem_fun(*this,&AppSlider::onClicked));
    //applyMargin(this->slider);

    //Image
    this->image = Gtk::Image();
    //applyMargin(this->image);

    //Box
    this->appWidget = Gtk::Box();
    pack();
}

void AppSlider::pack() {
    this->appWidget.pack_start(this->image, false, false);
    this->appWidget.pack_end(this->slider,true,true);
}

void AppSlider::onClicked() {
    this->properEvent->newValue(this->slider.get_value());
}

void AppSlider::style(std::string styleString) {
    this->image.set_from_icon_name(styleString,Gtk::IconSize(GTK_ICON_SIZE_LARGE_TOOLBAR));
}

Gtk::Box* AppSlider::getBox() {
    return &this->appWidget;
}

Gtk::Widget* AppSlider::getAppWidget() {
    return &this->slider;
}