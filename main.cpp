#include <iostream>
#include "gtk/RadioApp.h"

int main() {
    auto app = RadioApp::create();
    return app->run();
}
