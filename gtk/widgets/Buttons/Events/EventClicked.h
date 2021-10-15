#ifndef UNTITLED2_EVENTCLICKED_H
#define UNTITLED2_EVENTCLICKED_H
#include "Event.h"
#include "../../../../EventHandler.h"

enum Actions{
    PLAY,
    PAUSE,
    NEXT,
    PREVIOUS
};

class EventClicked : public Event{
    Actions action;
    EventHandler* eventHandler;
public:
    EventClicked(Actions action, EventHandler* eventHandler);
    void Clicked() override;
};


#endif //UNTITLED2_EVENTCLICKED_H
