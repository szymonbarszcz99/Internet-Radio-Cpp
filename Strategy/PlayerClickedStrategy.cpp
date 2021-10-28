#include "PlayerClickedStrategy.h"

void PlayerClickedStrategy::onClickedEvent() {
    switch (this->actionToDo) {
        case PLAY:
            this->playEventClicked();
            break;
        case PAUSE:
            this->pauseEventClicked();
            break;
        case NEXT:
            this->nextEventClicked();
            break;
        case PREVIOUS:
            this->previousEventClicked();
            break;
    }
}

void PlayerClickedStrategy::playEventClicked() {
    std::cout<<"Play clicked"<<std::endl;
    this->playerInterface->play();
}

void PlayerClickedStrategy::pauseEventClicked() {
    std::cout<<"Pause clicked"<<std::endl;
    this->playerInterface->pause();
}

void PlayerClickedStrategy::nextEventClicked() {
    std::cout<<"Next clicked"<<std::endl;
    this->linksInterface->setNextStation();
    this->playerInterface->changeStation(this->linksInterface->getCurrentLink());
    this->appWindowInterface->updateLabel(this->linksInterface->getCurrentName());
}

void PlayerClickedStrategy::previousEventClicked() {
    std::cout<<"Previous clicked"<<std::endl;
    this->linksInterface->setPreviousStation();
    this->playerInterface->changeStation(this->linksInterface->getCurrentLink());
    this->appWindowInterface->updateLabel(this->linksInterface->getCurrentName());
}

void PlayerClickedStrategy::setActionToDo(Actions action) {
    this->actionToDo = action;
}

void PlayerClickedStrategy::setAppWindowInterface(std::shared_ptr<AppWindowInterface> appWindowInterface) {
    this->appWindowInterface = appWindowInterface;
}


