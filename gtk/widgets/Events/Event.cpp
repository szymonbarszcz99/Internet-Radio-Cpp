#include "Event.h"

template<> void Event::eventPassArg<Actions>(Actions action) {

    if(action >= 0 && action <= 3){
        std::cout<<"Player strategy"<<std::endl;
        this->playerClickedStrategy->actionToDo = action;
        this->eventHandler->setStrategy(this->playerClickedStrategy);
        this->eventHandler->executeStrategy();
    } else{
        std::cout<<"Menubar strategy"<<std::endl;
        this->menubarClickedStrategy->actionToDo = action;
        this->eventHandler->setStrategy(this->menubarClickedStrategy);
        this->eventHandler->executeStrategy();
    }
}

template<> void Event::eventPassArg<double>(double volumeChanged){
    std::cout<<"Slider strategy"<<std::endl;
    this->sliderStrategy->volumeValue = volumeChanged;
    this->eventHandler->setStrategy(this->sliderStrategy);
    this->eventHandler->executeStrategy();
}

template<> void Event::eventPassArg<std::string, std::string, Actions>(std::string newName, std::string newLink, Actions actions) {
    std::cout<<"PopUpWindow strategy"<<std::endl;
    this->eventHandler->setStrategy(popUpWindowStrategy);
    this->popUpWindowStrategy->link = newLink;
    this->popUpWindowStrategy->name = newName;
    this->popUpWindowStrategy->actionToDo = actions;
    this->eventHandler->executeStrategy();
}

void Event::onStartup() {
    this->eventHandler->setStrategy(this->startupStrategy);
    this->eventHandler->executeStrategy();
}
