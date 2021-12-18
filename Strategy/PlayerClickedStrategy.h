#ifndef UNTITLED2_PLAYERCLICKEDSTRATEGY_H
#define UNTITLED2_PLAYERCLICKEDSTRATEGY_H
#pragma once
#include "ClickedStrategy.h"
#include <iostream>

class PlayerClickedStrategy : public ClickedStrategy{
    static void playEventClicked() ;
    static void pauseEventClicked() ;
    static void nextEventClicked() ;
    static void previousEventClicked() ;

public:

    void onClickedEvent() override;
    Actions actionToDo;

    ~PlayerClickedStrategy() override {
        std::cout<<"Player Clicked Strategy destructor"<<std::endl;
    }
};


#endif //UNTITLED2_PLAYERCLICKEDSTRATEGY_H
