#ifndef UNTITLED2_POPUPWINDOWVIEW_H
#define UNTITLED2_POPUPWINDOWVIEW_H
#pragma once
#include <utility>

#include "PopUpWindow.h"
        
class PopUpWindowView : public PopUpWindow{
    int top = 0;
public:
    explicit PopUpWindowView(const std::string& name): PopUpWindow(name){this->maximize();};
    void populate(const std::string& name, const std::string& link);
    ~PopUpWindowView() override{
        std::cout<<"Pop Up Window View destructor"<<std::endl;
    }
};


#endif //UNTITLED2_POPUPWINDOWVIEW_H
