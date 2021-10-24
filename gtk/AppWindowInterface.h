#ifndef UNTITLED2_APPWINDOWINTERFACE_H
#define UNTITLED2_APPWINDOWINTERFACE_H
#include <string>
#include "../links/LinksInterface.h"

class AppWindowInterface {

public:
    virtual void updateLabel(const std::string& newStation)=0;
    virtual void createPopUpWindow(const std::vector<Stations>& Stations)=0;
    virtual void createPopUpWindow2()=0;
    virtual ~AppWindowInterface() = default;
};


#endif //UNTITLED2_APPWINDOWINTERFACE_H
