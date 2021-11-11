#include "EventHandler.h"
#include "links/Links.h"
#include "gst/Player.h"
#include "gtk/RadioApp.h"

int main() {
    auto app = RadioApp::create();
    std::shared_ptr<EventHandler> eventHandler = std::make_shared<EventHandler>();

    app->setEventHandler(eventHandler);

    std::shared_ptr<Links> links = std::make_shared<Links>();
    std::shared_ptr<BusMessageStrategy> busMessageStrategy = std::make_shared<BusMessageStrategy>();
    std::unique_ptr<PlayerEvent> playerEvent = std::make_unique<PlayerEvent>(eventHandler,busMessageStrategy);
    std::shared_ptr<Player> player = std::make_shared<Player>(links->getCurrentLink(),std::move(playerEvent));



    std::shared_ptr<PlayerClickedStrategy> playerClickedStrategy = std::make_shared<PlayerClickedStrategy>(links,player);
    std::shared_ptr<MenubarClickedStrategy> menubarClickedStrategy = std::make_shared<MenubarClickedStrategy>(links,player);
    std::shared_ptr<PopUpWindowStrategy> popUpWindowStrategy = std::make_shared<PopUpWindowStrategy>(links, player);
    std::shared_ptr<SliderStrategy> sliderStrategy = std::make_shared<SliderStrategy>(player);
    std::shared_ptr<StartupStrategy> startupStrategy = std::make_shared<StartupStrategy>(links);

    app->setPlayerClickedStrategy(std::move(playerClickedStrategy))->setMenubarClickedStrategy(std::move(menubarClickedStrategy))
    ->setPopUpWindowStrategy(std::move(popUpWindowStrategy))->setSliderStrategy(std::move(sliderStrategy))
    ->setStartupStrategy(std::move(startupStrategy))->setBusMessageStrategy(std::move(busMessageStrategy));

    return app->run();;
}
