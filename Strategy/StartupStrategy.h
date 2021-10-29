#ifndef UNTITLED2_STARTUPSTRATEGY_H
#define UNTITLED2_STARTUPSTRATEGY_H
#include "ClickedStrategy.h"

class StartupStrategy : public ClickedStrategy{
    std::weak_ptr<AppWindowInterface> appWindowInterface;
    std::weak_ptr<LinksInterface> linksInterface;
public:
    StartupStrategy(std::shared_ptr<LinksInterface> linksInterface):linksInterface(linksInterface){}
    void onClickedEvent() override;
    ~StartupStrategy() {
        std::cout << "Startup Strategy destructor" << std::endl;
    }
    void setAppWindowInterface(std::shared_ptr<AppWindowInterface> appWindowInterface) override;
};


#endif //UNTITLED2_STARTUPSTRATEGY_H
