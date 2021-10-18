#include "AppWindowBuilder.h"

AppWindowBuilder::AppWindowBuilder(EventHandler* eventHandler){
    this->appWindow = (new AppWindow(eventHandler))->createLabel()->createButtons()->attachWidgets();
}

AppWindow *AppWindowBuilder::getAppWindow() {
    return this->appWindow;
}


