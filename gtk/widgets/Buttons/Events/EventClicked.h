#ifndef UNTITLED2_EVENTCLICKED_H
#define UNTITLED2_EVENTCLICKED_H
#include "Event.h"
#include "../../../../EventHandler.h"

class EventClicked : public Event{
    EventHandler* eventHandler;
public:
    EventClicked(EventHandler* eventHandler);
    void Clicked(Actions action) override;
};


#endif //UNTITLED2_EVENTCLICKED_H
