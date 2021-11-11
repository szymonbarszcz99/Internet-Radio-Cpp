#include "PlayerEvent.h"

template<> void PlayerEvent::playerEventPassArg<std::string>(std::string songName){
    std::cout<<"Song name received: "<<songName<<std::endl;
    this->busMessageStrategy->songName = songName;
    this->eventHandler->setStrategy(this->busMessageStrategy);
    this->eventHandler->executeStrategy();
}