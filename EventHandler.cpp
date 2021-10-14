#include "EventHandler.h"

EventHandler::EventHandler(LinksInterface &linksInterface1,
                           PlayerInterface &playerInterface1):
                           linksInterface(linksInterface1), playerInterface(playerInterface1)
                           {}
void EventHandler::onPlayClicked() {
    this->playerInterface.play();
}

void EventHandler::onPauseClicked() {
    this->playerInterface.pause();
}

void EventHandler::onNextClicked() {
    this->linksInterface.setNextStation();
    this->playerInterface.changeStation(this->linksInterface.getCurrentLink());
    this->appWindowInterface->updateLabel(this->linksInterface.getCurrentName());
}

void EventHandler::onPreviousClicked() {
    this->linksInterface.setPreviousStation();
    this->playerInterface.changeStation(this->linksInterface.getCurrentLink());
    this->appWindowInterface->updateLabel(this->linksInterface.getCurrentName());
}

void EventHandler::connectCreatedWindow(AppWindowInterface* appWindowInterface1) {
    this->appWindowInterface = appWindowInterface1;
}

void EventHandler::setStationNameOnStartup() {
    this->appWindowInterface->updateLabel(this->linksInterface.getCurrentName());
}
