#ifndef UNTITLED2_POPUPWINDOWVIEW_H
#define UNTITLED2_POPUPWINDOWVIEW_H
#pragma once
#include "PopUpWindow.h"

class PopUpWindowView : public PopUpWindow{
    int top = 0;
public:
    PopUpWindowView(std::string name): PopUpWindow(name){}
    void populate(std::string name, std::string link);
    ~PopUpWindowView() override{
        std::cout<<"Pop Up Window View destructor"<<std::endl;
    }
};


#endif //UNTITLED2_POPUPWINDOWVIEW_H
