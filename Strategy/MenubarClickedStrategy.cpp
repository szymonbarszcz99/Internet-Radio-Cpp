#include "MenubarClickedStrategy.h"

void MenubarClickedStrategy::onClickedEvent() {
    std::cout<<"Menubar value: "<<actionToDo<<std::endl;
    auto wsp = this->appWindowInterface.lock();
    auto lsp = this->linksInterface.lock();
    auto psp = this->playerInterface.lock();

    if(actionToDo == ADD_STATION)wsp->createPopUpWindowWrite("Add");
    else if(actionToDo == DELETE_STATION) {
        lsp->updateCurrent(FileLine::DELETE);
        lsp->setPreviousStation();
        wsp->updateLabel(lsp->getCurrentName());
        psp->changeStation(lsp->getCurrentLink());
    }
    else if(actionToDo == MODIFY_STATION)wsp->createPopUpWindowWrite("Update",lsp->getCurrentName(), lsp->getCurrentLink());
    else if(actionToDo == VIEW)wsp->createPopUpWindowView(lsp->getAllStations());
}
