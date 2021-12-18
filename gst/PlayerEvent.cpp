#include "PlayerEvent.h"

template<> void PlayerEvent::playerEventPassArg<const std::string&>(const std::string& arg){
    std::cout<<"Song name received: "<<arg<<std::endl;
    this->busMessageStrategy->songName = arg;
    this->eventHandler.setStrategy(this->busMessageStrategy);
    this->eventHandler.executeStrategy();
}