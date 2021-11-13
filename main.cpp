#include "EventHandler.h"
#include "links/Links.h"
#include "gst/Player.h"
#include "gtk/RadioApp.h"

int main() {
    std::shared_ptr<EventHandler> eventHandler = std::make_shared<EventHandler>();

    std::shared_ptr<Links> links = std::make_shared<Links>();
    ClickedStrategy::linksInterface = links;

    std::shared_ptr<BusMessageStrategy> busMessageStrategy = std::make_shared<BusMessageStrategy>();
    std::unique_ptr<PlayerEvent> playerEvent = std::make_unique<PlayerEvent>(eventHandler,busMessageStrategy);
    std::shared_ptr<Player> player = std::make_shared<Player>(links->getCurrentLink(),std::move(playerEvent));
    ClickedStrategy::playerInterface = player;

    std::shared_ptr<PlayerClickedStrategy> playerClickedStrategy = std::make_shared<PlayerClickedStrategy>();
    std::shared_ptr<MenubarClickedStrategy> menubarClickedStrategy = std::make_shared<MenubarClickedStrategy>();
    std::shared_ptr<PopUpWindowStrategy> popUpWindowStrategy = std::make_shared<PopUpWindowStrategy>();
    std::shared_ptr<SliderStrategy> sliderStrategy = std::make_shared<SliderStrategy>();
    std::shared_ptr<StartupStrategy> startupStrategy = std::make_shared<StartupStrategy>();

    auto app = RadioApp::create(eventHandler,playerClickedStrategy,menubarClickedStrategy,
                                popUpWindowStrategy,sliderStrategy,startupStrategy);

    return app->run();
}
