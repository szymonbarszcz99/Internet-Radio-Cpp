#ifndef UNTITLED2_SLIDERSTRATEGY_H
#define UNTITLED2_SLIDERSTRATEGY_H
#include "ClickedStrategy.h"

class SliderStrategy : public ClickedStrategy{
    std::shared_ptr<PlayerInterface> playerInterface;
    std::weak_ptr<AppWindowInterface> appWindowInterface;
    double volumeValue;
public:
    SliderStrategy(std::shared_ptr<PlayerInterface> playerInterface):playerInterface(playerInterface){}
    void setAppWindowInterface(std::shared_ptr<AppWindowInterface> appWindowInterface) override;
    void setVolume(double volume);
    void onClickedEvent() override;
    ~SliderStrategy() override{
        std::cout<<"Slider strategy destructor"<<std::endl;
    }
};


#endif //UNTITLED2_SLIDERSTRATEGY_H