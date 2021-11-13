#include "BusMessageStrategy.h"

void BusMessageStrategy::onClickedEvent() {
    auto sp = this->appWindowInterface.lock();
    sp->updateSongNameLabel(this->songName);
}