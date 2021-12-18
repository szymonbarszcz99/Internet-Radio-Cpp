#ifndef UNTITLED2_STARTUPSTRATEGY_H
#define UNTITLED2_STARTUPSTRATEGY_H
#pragma once
#include "ClickedStrategy.h"

class StartupStrategy : public ClickedStrategy{
public:
    void onClickedEvent() override;
    ~StartupStrategy() override {
        std::cout << "Startup Strategy destructor" << std::endl;
    }
};


#endif //UNTITLED2_STARTUPSTRATEGY_H
