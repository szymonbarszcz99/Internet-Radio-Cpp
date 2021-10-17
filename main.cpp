#include "EventHandler.h"
#include "links/Links.h"
#include "gst/Player.h"
#include "gtk/RadioApp.h"

int main() {
    auto app = RadioApp::create();
    EventHandler eventHandler;

    app->setEventHandler(&eventHandler); //For window's interface when the window is ready

    Links links;
    Player player(links.getCurrentLink());
    eventHandler.setLinksInterface(&links);
    eventHandler.setPlayerInterface(&player);
    return app->run();
}
