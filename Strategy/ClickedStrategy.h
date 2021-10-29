#ifndef UNTITLED2_CLICKEDSTRATEGY_H
#define UNTITLED2_CLICKEDSTRATEGY_H
#include "../gtk/AppWindowInterface.h"
#include "../gst/PlayerInterface.h"
#include "../gtk/widgets/Events/Enums.h"
#include <iostream>
#include "memory"

class ClickedStrategy {
public:
    virtual void onClickedEvent() = 0;
    virtual void setAppWindowInterface(std::shared_ptr<AppWindowInterface> appWindowInterface)=0;
    virtual ~ClickedStrategy(){}
};



#endif //UNTITLED2_CLICKEDSTRATEGY_H
