#ifndef UNTITLED2_EVENT_H
#define UNTITLED2_EVENT_H
#include <memory>
#include "../../../EventHandler.h"
#include "../../../Strategy/ClickedStrategy.h"
#include "../../../Strategy/PlayerClickedStrategy.h"
#include "Enums.h"
#include "../../../Strategy/MenubarClickedStrategy.h"
#include "../../../Strategy/PopUpWindowStrategy.h"
#include "../../../Strategy/SliderStrategy.h"

class Event {
    std::unique_ptr<EventHandler> eventHandler;
    std::shared_ptr<PlayerClickedStrategy> playerClickedStrategy;
    std::shared_ptr<MenubarClickedStrategy> menubarClickedStrategy;
    std::shared_ptr<PopUpWindowStrategy> popUpWindowStrategy;
    std::shared_ptr<SliderStrategy> sliderStrategy;
public:
    Event(std::unique_ptr<EventHandler>&& eventHandler,std::shared_ptr<PlayerClickedStrategy> playerClickedStrategy,
          std::shared_ptr<MenubarClickedStrategy> menubarClickedStrategy, std::shared_ptr<PopUpWindowStrategy> popUpWindowStrategy,
          std::shared_ptr<SliderStrategy> sliderStrategy):
     playerClickedStrategy(playerClickedStrategy),
    menubarClickedStrategy(menubarClickedStrategy),popUpWindowStrategy(popUpWindowStrategy),
    sliderStrategy(sliderStrategy){
        this->eventHandler = std::move(eventHandler);
    }

    template<typename ... name> void eventPassArg(name ...arg) {
        std::cout<<"Unknown value type"<<std::endl;
    }
};


#endif //UNTITLED2_EVENT_H
