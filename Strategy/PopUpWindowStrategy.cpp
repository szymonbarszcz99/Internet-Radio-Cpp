#include "PopUpWindowStrategy.h"

void PopUpWindowStrategy::onClickedEvent() {
    auto lsp = this->linksInterface.lock();
    switch(this->actionToDo){
        case ADD_STATION:
            lsp->appendStation(name,link);
            break;
        case MODIFY_STATION:
            lsp->modifyStation(name,link);
            auto sp = this->appWindowInterface.lock();
            const Stations& stations = lsp->getCurrentStation();
            sp->updateLabel(stations.StationName);
            break;
    }
}




