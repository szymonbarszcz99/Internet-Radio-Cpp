#include "PopUpWindowStrategy.h"

void PopUpWindowStrategy::setActionToDo(Actions action) {
    this->actionToDo = action;
}

void PopUpWindowStrategy::setAppWindowInterface(std::shared_ptr<AppWindowInterface> appWindowInterface) {
    this->appWindowInterface = appWindowInterface;
}

void PopUpWindowStrategy::onClickedEvent() {
    switch(this->actionToDo){
        case ADD_STATION:
            this->linksInterface->appendStation(name,link);
            break;
        case MODIFY_STATION:
            this->linksInterface->updateCurrent(MODIFY,name,link );
            this->appWindowInterface->updateLabel(linksInterface->getCurrentName());
            break;
    }
}

void PopUpWindowStrategy::setStrings(std::string name, std::string link) {
    this->name = name;
    this->link = link;
}




