#include "PlayerClickedStrategy.h"

void PlayerClickedStrategy::onClickedEvent() {
    switch (this->actionToDo) {
        case PLAY:
            PlayerClickedStrategy::playEventClicked();
            break;
        case PAUSE:
            PlayerClickedStrategy::pauseEventClicked();
            break;
        case NEXT:
            PlayerClickedStrategy::nextEventClicked();
            break;
        case PREVIOUS:
            PlayerClickedStrategy::previousEventClicked();
            break;
        default:
            break;
    }
}

void PlayerClickedStrategy::playEventClicked() {
    auto sp = PlayerClickedStrategy::playerInterface.lock();
    std::cout<<"Play clicked"<<std::endl;
    sp->play();
}

void PlayerClickedStrategy::pauseEventClicked() {
    std::cout<<"Pause clicked"<<std::endl;
    auto sp = PlayerClickedStrategy::playerInterface.lock();
    sp->pause();
}

void PlayerClickedStrategy::nextEventClicked() {
    std::cout<<"Next clicked"<<std::endl;
    auto psp = PlayerClickedStrategy::playerInterface.lock();
    auto lsp = PlayerClickedStrategy::linksInterface.lock();
    lsp->setNextStation();
    const Stations& stations = lsp->getCurrentStation();
    psp->changeStation(stations.StationLink);

    auto wsp = PlayerClickedStrategy::appWindowInterface.lock();
    wsp->updateLabel(stations.StationName);
    wsp->updateSongNameLabel("");
}

void PlayerClickedStrategy::previousEventClicked() {
    std::cout<<"Previous clicked"<<std::endl;
    auto psp = PlayerClickedStrategy::playerInterface.lock();
    auto lsp = PlayerClickedStrategy::linksInterface.lock();
    lsp->setPreviousStation();
    const Stations& stations = lsp->getCurrentStation();
    psp->changeStation(stations.StationLink);

    auto wsp = PlayerClickedStrategy::appWindowInterface.lock();
    wsp->updateLabel(stations.StationName);
    wsp->updateSongNameLabel("");
}


