#ifndef UNTITLED2_EVENT_H
#define UNTITLED2_EVENT_H

#include "../../../EventHandler.h"
#include "../../../Strategy/ClickedStrategy.h"
#include "../../../Strategy/PlayerClickedStrategy.h"
#include "Enums.h"
#include "../../../Strategy/MenubarClickedStrategy.h"
#include "../../../Strategy/PopUpWindowStrategy.h"
#include "../../../Strategy/SliderStrategy.h"

class Event {
    EventHandler* eventHandler;
    PlayerClickedStrategy* playerClickedStrategy;
    MenubarClickedStrategy* menubarClickedStrategy;
    PopUpWindowStrategy* popUpWindowStrategy;
    SliderStrategy* sliderStrategy;
public:
    Event(EventHandler* eventHandler,PlayerClickedStrategy* playerClickedStrategy, MenubarClickedStrategy* menubarClickedStrategy, PopUpWindowStrategy* popUpWindowStrategy,SliderStrategy* sliderStrategy):
    eventHandler(eventHandler),playerClickedStrategy(playerClickedStrategy),
    menubarClickedStrategy(menubarClickedStrategy),popUpWindowStrategy(popUpWindowStrategy),
    sliderStrategy(sliderStrategy){}

    template<typename ... name> void eventPassArg(name ...arg) {
        std::cout<<"Unknown value type"<<std::endl;
    }
};


#endif //UNTITLED2_EVENT_H
