#ifndef UNTITLED2_POPUPWINDOWVIEW_H
#define UNTITLED2_POPUPWINDOWVIEW_H
#include "PopUpWindow.h"

class PopUpWindowView : public PopUpWindow{
    int top = 0;
public:
    PopUpWindowView(std::string name): PopUpWindow(name){}
    void populate(std::string name, std::string link);

};


#endif //UNTITLED2_POPUPWINDOWVIEW_H
