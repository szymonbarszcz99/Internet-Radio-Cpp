#include "AppSlider.h"

AppSlider::AppSlider(EventValueChanged* properEvent): properEvent(properEvent){
    //Slider
    this->slider = Gtk::Scale();
    this->slider.set_digits(0);
    this->slider.set_range(0,100);
    this->slider.signal_value_changed().connect(sigc::mem_fun(*this,&AppSlider::onClicked));
    this->slider.set_value(50);
    //Image
    this->image = Gtk::Image();

    //Box
    this->appWidget = Gtk::Box();
    applyMargin(this->appWidget);
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

Gtk::Widget* AppSlider::getAppWidget() {
    return &this->appWidget;
}