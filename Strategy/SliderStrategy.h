#ifndef UNTITLED2_SLIDERSTRATEGY_H
#define UNTITLED2_SLIDERSTRATEGY_H
#pragma once
#include "ClickedStrategy.h"

class SliderStrategy : public ClickedStrategy{
public:
    void onClickedEvent() override;
    ~SliderStrategy() override{
        std::cout<<"Slider strategy destructor"<<std::endl;
    }
    double volumeValue;
};


#endif //UNTITLED2_SLIDERSTRATEGY_H
