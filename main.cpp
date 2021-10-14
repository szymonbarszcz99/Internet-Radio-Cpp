#include "gtk/RadioApp.h"
#include "gst/Player.h"
#include "links/Links.h"
#include "EventHandler.h"

int main() {
    auto app = RadioApp::create();
    Links links;
    Player player(links.getCurrentLink());

    EventHandler eventHandler( links, player);

    app->setHandler(&eventHandler);
    return app->run();
}
