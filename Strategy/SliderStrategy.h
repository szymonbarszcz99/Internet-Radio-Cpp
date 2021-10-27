#ifndef UNTITLED2_SLIDERSTRATEGY_H
#define UNTITLED2_SLIDERSTRATEGY_H
#include "ClickedStrategy.h"

class SliderStrategy : public ClickedStrategy{
    PlayerInterface* playerInterface;
    AppWindowInterface* appWindowInterface;
    double volumeValue;
public:
    SliderStrategy(PlayerInterface* playerInterface):playerInterface(playerInterface){}
    void setAppWindowInterface(AppWindowInterface* appWindowInterface) override;
    void setVolume(double volume);
    void onClickedEvent() override;
};


#endif //UNTITLED2_SLIDERSTRATEGY_H
