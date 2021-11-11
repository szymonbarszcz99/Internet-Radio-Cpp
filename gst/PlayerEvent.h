#ifndef UNTITLED2_PLAYEREVENT_H
#define UNTITLED2_PLAYEREVENT_H
#include "../Strategy/BusMessageStrategy.h"
#include "../EventHandler.h"

class PlayerEvent {
    std::shared_ptr<BusMessageStrategy> busMessageStrategy;
    std::shared_ptr<EventHandler> eventHandler;
public:
    PlayerEvent(std::shared_ptr<EventHandler> eventHandler,std::shared_ptr<BusMessageStrategy> busMessageStrategy):
    eventHandler(eventHandler),busMessageStrategy(busMessageStrategy){}

    template<typename ... name> void playerEventPassArg(name ...arg) {
        std::cout<<"Unknown value type"<<std::endl;
    }

};


#endif //UNTITLED2_PLAYEREVENT_H
