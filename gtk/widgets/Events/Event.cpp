#include "Event.h"

template<> void Event::eventPassArg<Actions>(Actions action) const{

    if(action >= 0 && action <= 3){
        std::cout<<"Player strategy"<<std::endl;
        this->playerClickedStrategy->actionToDo = action;
        this->eventHandler.setStrategy(this->playerClickedStrategy);
        this->eventHandler.executeStrategy();
    } else{
        std::cout<<"Menubar strategy"<<std::endl;
        this->menubarClickedStrategy->actionToDo = action;
        this->eventHandler.setStrategy(this->menubarClickedStrategy);
        this->eventHandler.executeStrategy();
    }
}

template<> void Event::eventPassArg<double>(double volumeChanged)const{
    std::cout<<"Slider strategy"<<std::endl;
    this->sliderStrategy->volumeValue = volumeChanged;
    this->eventHandler.setStrategy(this->sliderStrategy);
    this->eventHandler.executeStrategy();
}

template<> void Event::eventPassArg<std::string, std::string, Actions>(std::string newName, std::string newLink, Actions actions) const{
    std::cout<<"PopUpWindow strategy"<<std::endl;
    this->eventHandler.setStrategy(popUpWindowStrategy);
    this->popUpWindowStrategy->link = newLink;
    this->popUpWindowStrategy->name = newName;
    this->popUpWindowStrategy->actionToDo = actions;
    this->eventHandler.executeStrategy();
}

void Event::onStartup() const{
    this->eventHandler.setStrategy(this->startupStrategy);
    this->eventHandler.executeStrategy();
}

Event::Event(EventHandler& eventHandler):eventHandler(eventHandler) {
    this->playerClickedStrategy = std::make_shared<PlayerClickedStrategy>();
    this->menubarClickedStrategy = std::make_shared<MenubarClickedStrategy>();
    this->popUpWindowStrategy = std::make_shared<PopUpWindowStrategy>();
    this->sliderStrategy = std::make_shared<SliderStrategy>();
    this->startupStrategy = std::make_shared<StartupStrategy>();
}
