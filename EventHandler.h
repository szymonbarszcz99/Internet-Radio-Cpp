#ifndef UNTITLED2_EVENTHANDLER_H
#define UNTITLED2_EVENTHANDLER_H
#include "gtk/AppWindowInterface.h"
#include "gst/PlayerInterface.h"
#include "links/LinksInterface.h"
#include "Strategy/ClickedStrategy.h"
#include <iostream>

class EventHandler{
    ClickedStrategy* clickedStrategy = nullptr;
public:

    //Strategy setter
    void setStrategy(ClickedStrategy* clickedStrategy);

    //Execute proper strategy
    void executeStrategy();
};

#endif //UNTITLED2_EVENTHANDLER_H
