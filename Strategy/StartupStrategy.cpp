#include "StartupStrategy.h"

void StartupStrategy::onClickedEvent() {
    auto lsp = StartupStrategy::linksInterface.lock();
    auto wsp = StartupStrategy::appWindowInterface.lock();
    const Stations& stations = lsp->getCurrentStation();
    wsp->updateLabel(stations.StationName);

    const std::vector<std::pair<int,std::string>>& errorVector = lsp->getErrorVector();
    if(!errorVector.empty()){
        for(const auto& it: errorVector){
            wsp->throwModal(it.first,it.second);
        }
    }

}


