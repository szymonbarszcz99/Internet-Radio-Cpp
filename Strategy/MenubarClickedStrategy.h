#ifndef UNTITLED2_MENUBARCLICKEDSTRATEGY_H
#define UNTITLED2_MENUBARCLICKEDSTRATEGY_H
#include "ClickedStrategy.h"

class MenubarClickedStrategy : public ClickedStrategy{
    AppWindowInterface* appWindowInterface;
    LinksInterface* linksInterface;
    PlayerInterface* playerInterface;
    Actions actionToDo;

public:
    MenubarClickedStrategy( LinksInterface* linksInterface, PlayerInterface* playerInterface):
    linksInterface(linksInterface), playerInterface(playerInterface){};

    void onClickedEvent() override;

    void setActionToDo(Actions action);

    void setAppWindowInterface(AppWindowInterface *appWindowInterface) override;
};


#endif //UNTITLED2_MENUBARCLICKEDSTRATEGY_H
