#include "SliderStrategy.h"

void SliderStrategy::setAppWindowInterface(std::shared_ptr<AppWindowInterface> appWindowInterface) {
    this->appWindowInterface = appWindowInterface;
}

void SliderStrategy::setVolume(double volume) {
    this->volumeValue = volume;
}

void SliderStrategy::onClickedEvent() {
    std::cout<<"Volume: "<<this->volumeValue<<std::endl;
    this->playerInterface->setVolume(this->volumeValue);
}
