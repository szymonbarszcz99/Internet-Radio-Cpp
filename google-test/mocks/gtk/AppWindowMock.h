#ifndef UNTITLED2_APPWINDOWMOCK_H
#define UNTITLED2_APPWINDOWMOCK_H
#include "../../../gtk/widgets/Events/Event.h"
#include "../../../gst/PlayerEvent.h"
#include <gmock/gmock.h>

class AppWindowMock : public AppWindowInterface{
public:
    MOCK_METHOD(void,updateSongNameLabel,(const std::string& songName),(override));
    MOCK_METHOD(void,updateLabel,(const std::string& newStation),(override));
    MOCK_METHOD(void,createPopUpWindowView,(const std::vector<Stations>& Stations),(override));
    MOCK_METHOD(void,createPopUpWindowWrite,(std::string windowName, std::string nameEntry, std::string linkEntry),(override));
    MOCK_METHOD(void,throwModal,(int lineNumber, std::string text),(override));
    MOCK_METHOD(void,showWindow,(std::shared_ptr<Gtk::Window> windowToShow),(override));
    MOCK_METHOD(void,closeWindow,(),(override));
};


#endif //UNTITLED2_APPWINDOWMOCK_H
