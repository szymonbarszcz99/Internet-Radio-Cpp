#include "SliderStrategy.h"

void SliderStrategy::onClickedEvent() {
    auto sp = SliderStrategy::playerInterface.lock();
    std::cout<<"Volume: "<<this->volumeValue<<std::endl;
    sp->setVolume(this->volumeValue);
}
