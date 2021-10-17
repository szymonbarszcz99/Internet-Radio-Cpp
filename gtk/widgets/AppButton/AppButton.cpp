#include "AppButton.h"

AppButton::AppButton(Event *properEvent,Actions action):properEvent(properEvent),action(action) {
    this->appWidget = Gtk::Button();
    this->appWidget.signal_clicked().connect(sigc::mem_fun(*this,&AppButton::onClicked));
    applyMargin(this->appWidget);
}

void AppButton::style(std::string styleString) {
    this->appWidget.set_image_from_icon_name(styleString);
}

void AppButton::onClicked() {
    this->properEvent->Clicked(this->action);
}

Gtk::Widget* AppButton::getAppWidget(){
    return &this->appWidget;
}