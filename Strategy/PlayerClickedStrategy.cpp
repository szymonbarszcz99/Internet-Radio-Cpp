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
    auto sp = this->playerInterface.lock();
    std::cout<<"Play clicked"<<std::endl;
    sp->play();
}

void PlayerClickedStrategy::pauseEventClicked() {
    std::cout<<"Pause clicked"<<std::endl;
    auto sp = this->playerInterface.lock();
    sp->pause();
}

void PlayerClickedStrategy::nextEventClicked() {
    std::cout<<"Next clicked"<<std::endl;
    auto psp = this->playerInterface.lock();
    auto lsp = this->linksInterface.lock();
    lsp->setNextStation();
    psp->changeStation(lsp->getCurrentLink());

    auto wsp = this->appWindowInterface.lock();
    wsp->updateLabel(lsp->getCurrentName());
}

void PlayerClickedStrategy::previousEventClicked() {
    std::cout<<"Previous clicked"<<std::endl;
    auto psp = this->playerInterface.lock();
    auto lsp = this->linksInterface.lock();
    lsp->setPreviousStation();
    psp->changeStation(lsp->getCurrentLink());

    auto wsp = this->appWindowInterface.lock();
    wsp->updateLabel(lsp->getCurrentName());
}


