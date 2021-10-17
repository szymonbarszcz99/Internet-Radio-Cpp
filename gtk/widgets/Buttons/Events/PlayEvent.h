#ifndef UNTITLED2_PLAYEVENT_H
#define UNTITLED2_PLAYEVENT_H
#include "Event.h"
#include "../../../../EventHandler.h"

class PlayEvent : public Event{
    EventHandler* eventHandler;
public:
    void Clicked() override;
    PlayEvent(EventHandler* eventHandler);
};


#endif //UNTITLED2_PLAYEVENT_H
