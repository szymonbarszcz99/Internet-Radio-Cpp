#include "SliderStrategy.h"

void SliderStrategy::onClickedEvent() {
    auto sp = this->playerInterface.lock();
    std::cout<<"Volume: "<<this->volumeValue<<std::endl;
    sp->setVolume(this->volumeValue);
}
