#include <iostream>
#include "gtk/RadioApp.h"
#include "gst/Player.h"

int main() {
    auto app = RadioApp::create();
    Player player;
    return app->run();
}
