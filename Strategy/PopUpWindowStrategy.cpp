#include "PopUpWindowStrategy.h"

void PopUpWindowStrategy::onClickedEvent() {
    auto lsp = this->linksInterface.lock();
    switch(this->actionToDo){
        case ADD_STATION:
            lsp->appendStation(name,link);
            break;
        case MODIFY_STATION:
            lsp->updateCurrent(MODIFY,name,link );
            auto sp = this->appWindowInterface.lock();
            sp->updateLabel(lsp->getCurrentName());
            break;
    }
}




