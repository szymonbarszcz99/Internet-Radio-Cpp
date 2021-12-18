#ifndef UNTITLED2_EVENT_H
#define UNTITLED2_EVENT_H
#pragma once
#include "../../../EventHandler.h"
#include "../../../Strategy/PlayerClickedStrategy.h"
#include "../../../Strategy/MenubarClickedStrategy.h"
#include "../../../Strategy/PopUpWindowStrategy.h"
#include "../../../Strategy/SliderStrategy.h"
#include "../../../Strategy/StartupStrategy.h"

class Event {
    EventHandler& eventHandler;
    std::shared_ptr<PlayerClickedStrategy> playerClickedStrategy;
    std::shared_ptr<MenubarClickedStrategy> menubarClickedStrategy;
    std::shared_ptr<PopUpWindowStrategy> popUpWindowStrategy;
    std::shared_ptr<SliderStrategy> sliderStrategy;
    std::shared_ptr<StartupStrategy> startupStrategy;

public:
    explicit Event(EventHandler& eventHandler);

    template<typename ... name> void eventPassArg([[maybe_unused]] name ...arg) const {
        std::cout<<"Unknown value type"<<std::endl;
    }

    void onStartup() const;

    ~Event(){
        std::cout<<"Event destructor"<<std::endl;
    }
};


#endif //UNTITLED2_EVENT_H
