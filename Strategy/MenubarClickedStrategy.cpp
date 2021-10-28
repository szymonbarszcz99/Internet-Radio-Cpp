#include "MenubarClickedStrategy.h"

void MenubarClickedStrategy::setAppWindowInterface(std::shared_ptr<AppWindowInterface> appWindowInterface) {
    this->appWindowInterface = appWindowInterface;
}

void MenubarClickedStrategy::onClickedEvent() {
    std::cout<<"Menubar value: "<<actionToDo<<std::endl;
    if(actionToDo == ADD_STATION)this->appWindowInterface->createPopUpWindowWrite("Add");
    else if(actionToDo == DELETE_STATION) {
        this->linksInterface->updateCurrent(FileLine::DELETE);
        this->linksInterface->setPreviousStation();
        this->appWindowInterface->updateLabel(this->linksInterface->getCurrentName());
        this->playerInterface->changeStation(this->linksInterface->getCurrentLink());
    }
    else if(actionToDo == MODIFY_STATION)this->appWindowInterface->createPopUpWindowWrite("Update",linksInterface->getCurrentName(), linksInterface->getCurrentLink());
    else if(actionToDo == VIEW)this->appWindowInterface->createPopUpWindowView(linksInterface->getAllStations());
}

void MenubarClickedStrategy::setActionToDo(Actions action) {
    this->actionToDo = action;
}
