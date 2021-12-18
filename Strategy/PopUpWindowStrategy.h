#ifndef UNTITLED2_POPUPWINDOWSTRATEGY_H
#define UNTITLED2_POPUPWINDOWSTRATEGY_H

#pragma once
#include "ClickedStrategy.h"

class PopUpWindowStrategy : public ClickedStrategy{
    static void throwModalOnAppWindow(possibleErrors error) ;
public:
    Actions actionToDo;
    std::string name;
    std::string link;
    void onClickedEvent() override;

    ~PopUpWindowStrategy() override {
        std::cout<<"Pop Up Window Strategy destructor"<<std::endl;
    }
};


#endif //UNTITLED2_POPUPWINDOWSTRATEGY_H
