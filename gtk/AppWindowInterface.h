#ifndef UNTITLED2_APPWINDOWINTERFACE_H
#define UNTITLED2_APPWINDOWINTERFACE_H
#include <string>
#include "widgets/WidgetGrid/WidgetGrid.h"

class AppWindowInterface {

public:
    virtual void updateLabel(const std::string& newStation)=0;
    virtual WidgetGrid* getGrid()=0;
    virtual ~AppWindowInterface() = default;
};


#endif //UNTITLED2_APPWINDOWINTERFACE_H
