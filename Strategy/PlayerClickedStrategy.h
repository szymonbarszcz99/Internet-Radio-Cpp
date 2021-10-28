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
    std::shared_ptr<AppWindowInterface> appWindowInterface;
    std::shared_ptr<LinksInterface> linksInterface;
    std::shared_ptr<PlayerInterface> playerInterface;
public:
    PlayerClickedStrategy( std::shared_ptr<LinksInterface> linksInterface, std::shared_ptr<PlayerInterface> playerInterface):
             linksInterface(linksInterface), playerInterface(playerInterface){};

    void onClickedEvent() override;

    void setActionToDo(Actions action);

    void setAppWindowInterface(std::shared_ptr<AppWindowInterface> appWindowInterface) override;
};


#endif //UNTITLED2_PLAYERCLICKEDSTRATEGY_H
