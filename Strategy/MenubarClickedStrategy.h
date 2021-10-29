#ifndef UNTITLED2_MENUBARCLICKEDSTRATEGY_H
#define UNTITLED2_MENUBARCLICKEDSTRATEGY_H
#include "ClickedStrategy.h"

class MenubarClickedStrategy : public ClickedStrategy{
    std::weak_ptr<AppWindowInterface> appWindowInterface;
    std::shared_ptr<LinksInterface> linksInterface;
    std::shared_ptr<PlayerInterface> playerInterface;
    Actions actionToDo;

public:
    MenubarClickedStrategy( std::shared_ptr<LinksInterface> linksInterface, std::shared_ptr<PlayerInterface> playerInterface):
    linksInterface(linksInterface), playerInterface(playerInterface){};

    void onClickedEvent() override;

    void setActionToDo(Actions action);

    void setAppWindowInterface(std::shared_ptr<AppWindowInterface> appWindowInterface) override;

    ~MenubarClickedStrategy() override{
        std::cout<<"Menubar Strategy destructor"<<std::endl;
    }
};


#endif //UNTITLED2_MENUBARCLICKEDSTRATEGY_H