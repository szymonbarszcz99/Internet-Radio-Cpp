#ifndef UNTITLED2_EVENTCLICKED_H
#define UNTITLED2_EVENTCLICKED_H
#include "Event.h"
#include "../../../../EventHandler.h"

class EventClicked : public Event{
    EventHandler* eventHandler;
public:
    void Clicked(Actions action){
        switch (action) {
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
                break;
            case LABEL:
                this->eventHandler->labelClicked();
                break;
        }
    }
    EventClicked(EventHandler* eventHandler);
};


#endif //UNTITLED2_EVENTCLICKED_H
