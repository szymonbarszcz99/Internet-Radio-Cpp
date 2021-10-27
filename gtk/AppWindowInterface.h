#ifndef UNTITLED2_APPWINDOWINTERFACE_H
#define UNTITLED2_APPWINDOWINTERFACE_H
#include <string>
#include "../links/LinksInterface.h"

class AppWindowInterface {

public:
    virtual void updateLabel(const std::string& newStation)=0;
    virtual void createPopUpWindowView(const std::vector<Stations>& Stations)=0;
    virtual void createPopUpWindowWrite(std::string windowName, std::string nameEntry = "", std::string linkEntry = "")=0;
    virtual ~AppWindowInterface() = default;
};


#endif //UNTITLED2_APPWINDOWINTERFACE_H
