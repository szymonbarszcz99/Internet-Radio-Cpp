#ifndef UNTITLED2_EVENTHANDLER_H
#define UNTITLED2_EVENTHANDLER_H
#include "gtk/AppWindowInterface.h"
#include "gst/PlayerInterface.h"
#include "links/LinksInterface.h"
#include <iostream>
//TODO apply mediator
class EventHandler{
    AppWindowInterface* appWindowInterface = nullptr;
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

    //GUI Slider event
    void sliderValueChanged(double newValue);

    //GUI Menubar event
    void menubarClicked(int optionChoosen);

    //GUI Pop up window event
    void updateFile(std::string newName, std::string newLink);
    void addToFile(std::string newName, std::string newLink);

    //Interface setters
    void setAppWindowInterface(AppWindowInterface* appWindowInterface);
    void setPlayerInterface(PlayerInterface *playerInterface);
    void setLinksInterface(LinksInterface *linksInterface);
};


#endif //UNTITLED2_EVENTHANDLER_H
