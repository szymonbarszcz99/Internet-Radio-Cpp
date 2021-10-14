#ifndef UNTITLED2_GUIEVENTHANDLER_H
#define UNTITLED2_GUIEVENTHANDLER_H
#include "AppWindowInterface.h"

class GuiEventHandler{
public:
    virtual void onPlayClicked()=0;
    virtual void onPauseClicked()=0;
    virtual void onNextClicked()=0;
    virtual void onPreviousClicked()=0;
    virtual void connectCreatedWindow(AppWindowInterface* appWindow)=0;
    virtual void setStationNameOnStartup()=0;
};

#endif //UNTITLED2_GUIEVENTHANDLER_H
