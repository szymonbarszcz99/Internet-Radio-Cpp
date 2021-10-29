#ifndef UNTITLED2_POPUPWINDOWSTRATEGY_H
#define UNTITLED2_POPUPWINDOWSTRATEGY_H


#include "ClickedStrategy.h"

class PopUpWindowStrategy : public ClickedStrategy{
    Actions actionToDo;
    std::string name;
    std::string link;
    std::weak_ptr<AppWindowInterface> appWindowInterface;
    std::shared_ptr<LinksInterface> linksInterface;
    std::shared_ptr<PlayerInterface> playerInterface;
public:
    PopUpWindowStrategy( std::shared_ptr<LinksInterface> linksInterface, std::shared_ptr<PlayerInterface> playerInterface):
    linksInterface(linksInterface), playerInterface(playerInterface){};

    void onClickedEvent() override;

    void setActionToDo(Actions action);

    void setStrings(std::string name, std::string link);

    void setAppWindowInterface(std::shared_ptr<AppWindowInterface> appWindowInterface) override;

    ~PopUpWindowStrategy() override {
        std::cout<<"Pop Up Window Strategy destructor"<<std::endl;
    }
};


#endif //UNTITLED2_POPUPWINDOWSTRATEGY_H
