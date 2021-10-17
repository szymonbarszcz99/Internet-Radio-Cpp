#ifndef UNTITLED2_PAUSEEVENT_H
#define UNTITLED2_PAUSEEVENT_H
#include "Event.h"
#include "../../../../EventHandler.h"

class PauseEvent : public Event{
    EventHandler* eventHandler;
public:
    PauseEvent(EventHandler* eventHandler);
    void Clicked() override;
};


#endif //UNTITLED2_PAUSEEVENT_H
