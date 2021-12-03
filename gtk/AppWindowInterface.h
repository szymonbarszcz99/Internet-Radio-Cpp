#ifndef UNTITLED2_APPWINDOWINTERFACE_H
#define UNTITLED2_APPWINDOWINTERFACE_H
#include <string>
#include "../links/LinksInterface.h"
#include <memory>
#include <gtkmm/window.h>

class AppWindowInterface {

public:
    virtual void updateLabel(const std::string& newStation)=0;
    virtual void updateSongNameLabel(const std::string& songName)=0 ;
    virtual void createPopUpWindowView(const std::vector<Stations>& Stations)=0;
    virtual void createPopUpWindowWrite(std::string windowName, std::string nameEntry = "", std::string linkEntry = "")=0;
    virtual ~AppWindowInterface(){};
    virtual void throwModal(int lineNumber, std::string text) = 0;
    virtual void showWindow(std::shared_ptr<Gtk::Window> windowToShow) = 0;
};


#endif //UNTITLED2_APPWINDOWINTERFACE_H
