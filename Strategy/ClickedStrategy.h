#ifndef UNTITLED2_CLICKEDSTRATEGY_H
#define UNTITLED2_CLICKEDSTRATEGY_H
#include "../gtk/AppWindowInterface.h"
#include "../gst/PlayerInterface.h"
#include "../gtk/widgets/Events/Enums.h"
#include <iostream>

class ClickedStrategy {
public:
    virtual void onClickedEvent() = 0;
    virtual void setAppWindowInterface(AppWindowInterface *appWindowInterface)=0;
};



#endif //UNTITLED2_CLICKEDSTRATEGY_H
