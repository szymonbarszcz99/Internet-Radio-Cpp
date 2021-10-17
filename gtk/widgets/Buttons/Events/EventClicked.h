#ifndef UNTITLED2_EVENTCLICKED_H
#define UNTITLED2_EVENTCLICKED_H
#include "Event.h"
#include "../../../../EventHandler.h"

class EventClicked : public Event{
    EventHandler* eventHandler;
public:
    void Clicked(Actions action) override;
    EventClicked(EventHandler* eventHandler);
};


#endif //UNTITLED2_EVENTCLICKED_H
