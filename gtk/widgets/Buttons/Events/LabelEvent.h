#ifndef UNTITLED2_LABELEVENT_H
#define UNTITLED2_LABELEVENT_H
#include "Event.h"
#include "../../../../EventHandler.h"

class LabelEvent : public Event{
    EventHandler* eventHandler;
public:
    LabelEvent(EventHandler* eventHandler);
    void Clicked() override;
};


#endif //UNTITLED2_LABELEVENT_H
