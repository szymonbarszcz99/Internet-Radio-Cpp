#ifndef UNTITLED2_PLAYERCLICKEDSTRATEGY_H
#define UNTITLED2_PLAYERCLICKEDSTRATEGY_H
#include "ClickedStrategy.h"
#include <iostream>

class PlayerClickedStrategy : public ClickedStrategy{
    void playEventClicked();
    void pauseEventClicked();
    void nextEventClicked();
    void previousEventClicked();
    Actions actionToDo;
    AppWindowInterface* appWindowInterface;
    LinksInterface* linksInterface;
    PlayerInterface* playerInterface;
public:
    PlayerClickedStrategy( LinksInterface* linksInterface, PlayerInterface* playerInterface):
             linksInterface(linksInterface), playerInterface(playerInterface){};

    void onClickedEvent() override;

    void setActionToDo(Actions action);

    void setAppWindowInterface(AppWindowInterface *appWindowInterface) override;
};


#endif //UNTITLED2_PLAYERCLICKEDSTRATEGY_H
