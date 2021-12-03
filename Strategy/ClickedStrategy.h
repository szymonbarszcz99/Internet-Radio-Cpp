#ifndef UNTITLED2_CLICKEDSTRATEGY_H
#define UNTITLED2_CLICKEDSTRATEGY_H
#include "../gtk/AppWindowInterface.h"
#include "../gst/PlayerInterface.h"
#include "../gtk/widgets/Events/Enums.h"
#include <iostream>
#include "memory"

class ClickedStrategy {


public:
    inline static std::weak_ptr<AppWindowInterface> appWindowInterface;
    inline static std::weak_ptr<PlayerInterface> playerInterface;
    inline static std::weak_ptr<LinksInterface> linksInterface;
    virtual void onClickedEvent() = 0;
    virtual ~ClickedStrategy(){}
};



#endif //UNTITLED2_CLICKEDSTRATEGY_H
