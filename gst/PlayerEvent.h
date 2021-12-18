#ifndef UNTITLED2_PLAYEREVENT_H
#define UNTITLED2_PLAYEREVENT_H
#include "../Strategy/BusMessageStrategy.h"
#include "../EventHandler.h"

class PlayerEvent {
    std::shared_ptr<BusMessageStrategy> busMessageStrategy;
    EventHandler& eventHandler;
public:
    explicit PlayerEvent(EventHandler& eventHandler):
    eventHandler(eventHandler){
        this->busMessageStrategy = std::make_shared<BusMessageStrategy>();
    }

    template<typename  name> void playerEventPassArg([[maybe_unused]] name arg) {
        std::cout<<"Unknown value type"<<typeid(arg).name()<<std::endl;
    }

};


#endif //UNTITLED2_PLAYEREVENT_H
