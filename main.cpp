#include "EventHandler.h"
#include "links/Links.h"
#include "gst/Player.h"
#include "gtk/RadioApp.h"

int main() {
    auto app = RadioApp::create();
    EventHandler eventHandler;

    app->setEventHandler(&eventHandler);

    Links links;
    Player player(links.getCurrentLink());

    PlayerClickedStrategy playerClickedStrategy(&links,&player);
    MenubarClickedStrategy menubarClickedStrategy(&links,&player);
    PopUpWindowStrategy popUpWindowStrategy(&links, &player);
    SliderStrategy sliderStrategy(&player);

    app->setPlayerClickedStrategy(&playerClickedStrategy)->setMenubarClickedStrategy(&menubarClickedStrategy)
    ->setPopUpWindowStrategy(&popUpWindowStrategy)->setSliderStrategy(&sliderStrategy);
    return app->run();
}
