#include "AppButton.h"

AppButton::AppButton(Event *properEvent,Actions action):properEvent(properEvent),action(action) {

    this->signal_clicked().connect(sigc::mem_fun(*this,&AppButton::onClicked));
    this->property_margin() = 10;

    switch(this->action){
        case PLAY:
            this->set_image_from_icon_name("media-playback-start");
            break;
        case PAUSE:
            this->set_image_from_icon_name("media-playback-pause");
            break;
        case PREVIOUS:
            this->set_image_from_icon_name("media-seek-backward");
            break;
        case NEXT:
            this->set_image_from_icon_name("media-seek-forward");
            break;
    }
}

void AppButton::onClicked() {
    this->properEvent->eventPassArg(this->action);
}
