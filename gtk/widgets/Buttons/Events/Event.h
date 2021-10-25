#ifndef UNTITLED2_EVENT_H
#define UNTITLED2_EVENT_H

#include "../../../../EventHandler.h"

enum Actions{
    PLAY,
    PAUSE,
    NEXT,
    PREVIOUS,
    LABEL
};

class Event {
    EventHandler* eventHandler;
public:
    Event(EventHandler* eventHandler):eventHandler(eventHandler){}

    template<typename ... name> void eventPassArg(name ...arg) {
        std::cout<<"Unknown value type"<<std::endl;
    }
};


#endif //UNTITLED2_EVENT_H
