#include "SliderStrategy.h"

void SliderStrategy::setAppWindowInterface(AppWindowInterface *appWindowInterface) {
    this->appWindowInterface = appWindowInterface;
}

void SliderStrategy::setVolume(double volume) {
    this->volumeValue = volume;
}

void SliderStrategy::onClickedEvent() {
    std::cout<<std::endl<<"Slider strategy"<<std::endl;
    std::cout<<"Volume: "<<this->volumeValue<<std::endl;
    this->playerInterface->setVolume(this->volumeValue);
}
