#include "EventClicked.h"

EventClicked::EventClicked(Actions action,EventHandler* eventHandler):action(action) {
    this->eventHandler = eventHandler;
}

void EventClicked::Clicked() {
    switch(this->action){
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