#ifndef UNTITLED2_EVENTHANDLER_H
#define UNTITLED2_EVENTHANDLER_H
#include "Strategy/ClickedStrategy.h"
#include <iostream>
#include <memory>

class EventHandler{
    std::weak_ptr<ClickedStrategy> clickedStrategy;
public:

    //Strategy setter
    void setStrategy(const std::shared_ptr<ClickedStrategy>& clickedStrategy);

    //Execute proper strategy
    void executeStrategy();

    ~EventHandler(){
        std::cout<<"Event Handler Destructor"<<std::endl;
    }
};

#endif //UNTITLED2_EVENTHANDLER_H
