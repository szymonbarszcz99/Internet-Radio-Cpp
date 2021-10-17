#include "ButtonFactory.h"

ButtonFactory::ButtonFactory(const char* icon, Event* eventClicked, Actions action):Gtk::Button(), action(action){
    this->eventClicked = eventClicked;
    this->signal_clicked().connect(sigc::mem_fun(*this,&ButtonFactory::onClicked));

    set_image_from_icon_name(icon);
    set_margin_start(10);
    set_margin_end(10);
    set_margin_top(10);
    set_margin_bottom(10);
}

void ButtonFactory::onClicked() {
    this->eventClicked->Clicked(action);
}
