#include "MenubarClickedStrategy.h"

void MenubarClickedStrategy::setAppWindowInterface(std::shared_ptr<AppWindowInterface> appWindowInterface) {
    this->appWindowInterface = appWindowInterface;
}

void MenubarClickedStrategy::onClickedEvent() {
    std::cout<<"Menubar value: "<<actionToDo<<std::endl;
    auto sp = this->appWindowInterface.lock();

    if(actionToDo == ADD_STATION)sp->createPopUpWindowWrite("Add");
    else if(actionToDo == DELETE_STATION) {
        this->linksInterface->updateCurrent(FileLine::DELETE);
        this->linksInterface->setPreviousStation();
        sp->updateLabel(this->linksInterface->getCurrentName());
        this->playerInterface->changeStation(this->linksInterface->getCurrentLink());
    }
    else if(actionToDo == MODIFY_STATION)sp->createPopUpWindowWrite("Update",linksInterface->getCurrentName(), linksInterface->getCurrentLink());
    else if(actionToDo == VIEW)sp->createPopUpWindowView(linksInterface->getAllStations());
}

void MenubarClickedStrategy::setActionToDo(Actions action) {
    this->actionToDo = action;
}
