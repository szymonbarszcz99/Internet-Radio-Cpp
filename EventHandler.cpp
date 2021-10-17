#include "EventHandler.h"

void EventHandler::setAppWindowInterface(AppWindowInterface* appWindowInterface1) {
    this->appWindowInterface = appWindowInterface1;
}

void EventHandler::playEventClicked() {
    std::cout<<"Play clicked"<<std::endl;
    this->playerInterface->play();
}

void EventHandler::pauseEventClicked() {
    std::cout<<"Pause clicked"<<std::endl;
    this->playerInterface->pause();
}

void EventHandler::nextEventClicked() {
    std::cout<<"Next clicked"<<std::endl;
    this->linksInterface->setNextStation();
    this->playerInterface->changeStation(this->linksInterface->getCurrentLink());
    this->appWindowInterface->updateLabel(this->linksInterface->getCurrentName());
}

void EventHandler::previousEventClicked() {
    std::cout<<"Previous clicked"<<std::endl;
    this->linksInterface->setPreviousStation();
    this->playerInterface->changeStation(this->linksInterface->getCurrentLink());
    this->appWindowInterface->updateLabel(this->linksInterface->getCurrentName());
}

void EventHandler::setPlayerInterface(PlayerInterface *playerInterface1) {
    this->playerInterface = playerInterface1;
}

void EventHandler::setLinksInterface(LinksInterface *linksInterface1) {
    this->linksInterface = linksInterface1;
}
