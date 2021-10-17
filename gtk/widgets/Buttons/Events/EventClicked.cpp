#include "EventClicked.h"

EventClicked::EventClicked(EventHandler* eventHandler) {
    this->eventHandler = eventHandler;
}

void EventClicked::Clicked(Actions action) {
    switch(action){
        case PLAY:
            this->eventHandler->playEventClicked();
            break;
        case PAUSE:
            this->eventHandler->pauseEventClicked();
            break;
        case NEXT:
            this->eventHandler->nextEventClicked();
            break;
        case PREVIOUS:
            this->eventHandler->previousEventClicked();
    }
}