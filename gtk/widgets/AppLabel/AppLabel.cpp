#include "AppLabel.h"

AppLabel::AppLabel(Event *properEvent): properEvent(properEvent) {
    //this->signal_clicked().connect(sigc::mem_fun(*this,&ButtonFactory::onClicked));
    //TODO add click on widget to display info

    this->appWidget = Gtk::Label();
    applyMargin(this->appWidget);
}

void AppLabel::style(std::string styleString) {
    this->appWidget.set_text(styleString);
}

void AppLabel::onClicked() {
    properEvent->eventPassArg(this->action);
}

Gtk::Widget* AppLabel::getAppWidget(){
    return &this->appWidget;
}