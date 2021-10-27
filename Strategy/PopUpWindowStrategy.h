#ifndef UNTITLED2_POPUPWINDOWSTRATEGY_H
#define UNTITLED2_POPUPWINDOWSTRATEGY_H


#include "ClickedStrategy.h"

class PopUpWindowStrategy : public ClickedStrategy{
    Actions actionToDo;
    std::string name;
    std::string link;
    AppWindowInterface* appWindowInterface;
    LinksInterface* linksInterface;
    PlayerInterface* playerInterface;
public:
    PopUpWindowStrategy( LinksInterface* linksInterface, PlayerInterface* playerInterface):
    linksInterface(linksInterface), playerInterface(playerInterface){};

    void onClickedEvent() override;

    void setActionToDo(Actions action);

    void setStrings(std::string name, std::string link);

    void setAppWindowInterface(AppWindowInterface *appWindowInterface) override;
};


#endif //UNTITLED2_POPUPWINDOWSTRATEGY_H
