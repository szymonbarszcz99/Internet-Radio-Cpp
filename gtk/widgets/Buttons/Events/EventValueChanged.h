#ifndef UNTITLED2_EVENTVALUECHANGED_H
#define UNTITLED2_EVENTVALUECHANGED_H
#include "Event.h"
#include "../../../../EventHandler.h"

class EventValueChanged {
    EventHandler* eventHandler;
public:
    EventValueChanged(EventHandler* eventHandler);
    template<class name>void newValue(name value){
        eventHandler->sliderValueChanged(value);
    };
};


#endif //UNTITLED2_EVENTVALUECHANGED_H
