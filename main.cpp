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
    app->setPlayerClickedStrategy(&playerClickedStrategy);

    MenubarClickedStrategy menubarClickedStrategy(&links,&player);
    app->setMenubarClickedStrategy(&menubarClickedStrategy);

    PopUpWindowStrategy popUpWindowStrategy(&links, &player);
    app->setPopUpWindowStrategy(&popUpWindowStrategy);

    SliderStrategy sliderStrategy(&player);
    app->setSliderStrategy(&sliderStrategy);

    return app->run();
}
