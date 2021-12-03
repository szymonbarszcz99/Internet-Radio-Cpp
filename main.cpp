#include "EventHandler.h"
#include "links/Links.h"
#include "gst/Player.h"
#include "gtk/RadioApp.h"

int main() {
    EventHandler eventHandler;

    std::shared_ptr<Links> links = std::make_shared<Links>();

    std::unique_ptr<PlayerEvent> playerEvent = std::make_unique<PlayerEvent>(eventHandler);
    std::shared_ptr<Player> player = std::make_shared<Player>(links->getCurrentStation().StationLink,std::move(playerEvent));

    ClickedStrategy::playerInterface = player;
    ClickedStrategy::linksInterface = links;

    //Command from design pattern
    Event event(eventHandler);

    auto app = RadioApp::create(event);
    std::cout<<"12:01"<<std::endl;
    return app->run();
}
