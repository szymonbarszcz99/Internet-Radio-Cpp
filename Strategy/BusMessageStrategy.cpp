#include "BusMessageStrategy.h"

void BusMessageStrategy::setAppWindowInterface(std::shared_ptr<AppWindowInterface> appWindowInterface) {
    this->appWindowInterface = appWindowInterface;
}

void BusMessageStrategy::onClickedEvent() {
    auto sp = this->appWindowInterface.lock();
    sp->updateSongNameLabel(this->songName);
}