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
#include "../../../Strategy/StartupStrategy.h"
#include "../../../Strategy/BusMessageStrategy.h"
#include "../../../Strategy/ClickedStrategy.h"

class Event {
    EventHandler& eventHandler;
    std::shared_ptr<PlayerClickedStrategy> playerClickedStrategy;
    std::shared_ptr<MenubarClickedStrategy> menubarClickedStrategy;
    std::shared_ptr<PopUpWindowStrategy> popUpWindowStrategy;
    std::shared_ptr<SliderStrategy> sliderStrategy;
    std::shared_ptr<StartupStrategy> startupStrategy;

public:
    Event(EventHandler& eventHandler);

    template<typename ... name> void eventPassArg(name ...arg) const {
        std::cout<<"Unknown value type"<<std::endl;
    }

    void onStartup() const;

    ~Event(){
        std::cout<<"Event destructor"<<std::endl;
    }
};


#endif //UNTITLED2_EVENT_H
