#include "Event.h"

template<> void Event::eventPassArg<Actions>(Actions action) {

    if(action >= 0 && action <= 3){
        std::cout<<"Player strategy"<<std::endl;
        this->playerClickedStrategy->setActionToDo(action);
        this->eventHandler->setStrategy(this->playerClickedStrategy);
        this->eventHandler->executeStrategy();
    } else{
        std::cout<<"Menubar strategy"<<std::endl;
        this->menubarClickedStrategy->setActionToDo(action);
        this->eventHandler->setStrategy(this->menubarClickedStrategy);
        this->eventHandler->executeStrategy();
    }
}

template<> void Event::eventPassArg<double>(double volumeChanged){
    std::cout<<"Slider strategy"<<std::endl;
    this->sliderStrategy->setVolume(volumeChanged);
    this->eventHandler->setStrategy(this->sliderStrategy);
    this->eventHandler->executeStrategy();
}

template<> void Event::eventPassArg<std::string, std::string, Actions>(std::string newName, std::string newLink, Actions actions) {
    std::cout<<"PopUpWindow strategy"<<std::endl;
    this->eventHandler->setStrategy(popUpWindowStrategy);
    this->popUpWindowStrategy->setStrings(newName, newLink);
    this->popUpWindowStrategy->setActionToDo(actions);
    this->eventHandler->executeStrategy();
}