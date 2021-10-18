#ifndef UNTITLED2_APPWINDOWBUILDER_H
#define UNTITLED2_APPWINDOWBUILDER_H
#include "../AppWindow.h"

//More like a director in Builder design pattern
class AppWindowBuilder {
    AppWindow* appWindow;
public:
    AppWindowBuilder(EventHandler* eventHandler);
    AppWindow* getAppWindow();
};


#endif //UNTITLED2_APPWINDOWBUILDER_H
