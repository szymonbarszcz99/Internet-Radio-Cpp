#include "StartupStrategy.h"

void StartupStrategy::onClickedEvent() {
    auto lsp = this->linksInterface.lock();
    auto wsp = this->appWindowInterface.lock();
    wsp->updateLabel(lsp->getCurrentName());

    const std::vector<std::pair<int,std::string>>& errorVector = lsp->getErrorVector();
    if(!errorVector.empty()){
        for(auto it: errorVector){
            wsp->throwModal(it.first,it.second);
        }
    }

}


