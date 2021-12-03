#ifndef UNTITLED2_BUSMESSAGESTRATEGY_H
#define UNTITLED2_BUSMESSAGESTRATEGY_H
#include "ClickedStrategy.h"

class BusMessageStrategy : public ClickedStrategy{
public:
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