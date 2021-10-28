#ifndef UNTITLED2_EVENTHANDLER_H
#define UNTITLED2_EVENTHANDLER_H
#include "Strategy/ClickedStrategy.h"
#include <iostream>
#include <memory>

class EventHandler{
    std::shared_ptr<ClickedStrategy> clickedStrategy;
public:

    //Strategy setter
    void setStrategy(const std::shared_ptr<ClickedStrategy>& clickedStrategy);

    //Execute proper strategy
    void executeStrategy();
};

#endif //UNTITLED2_EVENTHANDLER_H
