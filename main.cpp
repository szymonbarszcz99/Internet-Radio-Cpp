#include "gtk/RadioApp.h"
#include "gst/Player.h"
#include "links/Links.h"

int main() {
    auto app = RadioApp::create();
    Links links;
    Player player;

    return app->run();
}
