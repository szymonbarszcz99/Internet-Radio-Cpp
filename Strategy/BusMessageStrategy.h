#ifndef UNTITLED2_BUSMESSAGESTRATEGY_H
#define UNTITLED2_BUSMESSAGESTRATEGY_H
#include "ClickedStrategy.h"

class BusMessageStrategy : public ClickedStrategy{
    std::weak_ptr<AppWindowInterface> appWindowInterface;
public:
    void setAppWindowInterface(std::shared_ptr<AppWindowInterface> appWindowInterface) override;
    void onClickedEvent() override;
    ~BusMessageStrategy(){
        std::cout<<"BusMessageStrategy destructor"<<std::endl;
    }
    BusMessageStrategy(){
        std::cout<<"BusMessageStrategy constructor"<<std::endl;
    }
    std::string songName;
};


#endif //UNTITLED2_BUSMESSAGESTRATEGY_H
