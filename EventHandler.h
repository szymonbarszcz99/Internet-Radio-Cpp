#ifndef UNTITLED2_EVENTHANDLER_H
#define UNTITLED2_EVENTHANDLER_H
#include "gtk/GuiEventHandler.h"
#include "gtk/AppWindowInterface.h"
#include "links/LinksInterface.h"
#include "gst/PlayerInterface.h"

class EventHandler : public GuiEventHandler{
    AppWindowInterface* appWindowInterface = nullptr;
    LinksInterface& linksInterface;
    PlayerInterface& playerInterface;

    void onPlayClicked() override;
    void onPauseClicked() override;
    void onNextClicked() override;
    void onPreviousClicked() override;
    void connectCreatedWindow(AppWindowInterface* appWindowInterface1) override;
    void setStationNameOnStartup() override;

public:
    EventHandler(LinksInterface& linksInterface1, PlayerInterface& playerInterface1);
};


#endif //UNTITLED2_EVENTHANDLER_H
