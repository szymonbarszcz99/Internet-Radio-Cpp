#ifndef UNTITLED2_PLAYERCLICKEDSTRATEGY_H
#define UNTITLED2_PLAYERCLICKEDSTRATEGY_H
#include "ClickedStrategy.h"
#include <iostream>

class PlayerClickedStrategy : public ClickedStrategy{
    void playEventClicked();
    void pauseEventClicked();
    void nextEventClicked();
    void previousEventClicked();

public:

    void onClickedEvent() override;
    Actions actionToDo;

    ~PlayerClickedStrategy() override {
        std::cout<<"Player Clicked Strategy destructor"<<std::endl;
    }
};


#endif //UNTITLED2_PLAYERCLICKEDSTRATEGY_H
