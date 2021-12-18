#include "BusMessageStrategy.h"

void BusMessageStrategy::onClickedEvent() {
    auto sp = BusMessageStrategy::appWindowInterface.lock();
    sp->updateSongNameLabel(this->songName);
}