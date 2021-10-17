#ifndef UNTITLED2_EVENTHANDLER_H
#define UNTITLED2_EVENTHANDLER_H
#include "gtk/AppWindowInterface.h"
#include "gst/PlayerInterface.h"
#include "links/LinksInterface.h"
#include <iostream>

class EventHandler{
    AppWindowInterface* appWindowInterface;
    PlayerInterface* playerInterface = nullptr;
    LinksInterface* linksInterface = nullptr;
public:
    //GUI Buttons events
    void playEventClicked();
    void pauseEventClicked();
    void nextEventClicked();
    void previousEventClicked();

    //GUI Label event
    void labelClicked();

    //Interface setters
    void setAppWindowInterface(AppWindowInterface* appWindowInterface);
    void setPlayerInterface(PlayerInterface *playerInterface);
    void setLinksInterface(LinksInterface *linksInterface);
};


#endif //UNTITLED2_EVENTHANDLER_H
