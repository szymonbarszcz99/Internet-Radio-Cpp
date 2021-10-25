#include "Event.h"

template<> void Event::eventPassArg<Actions>(Actions action) {
    switch (action) {
        case PLAY:
            this->eventHandler->playEventClicked();
            break;
        case PAUSE:
            this->eventHandler->pauseEventClicked();
            break;
        case NEXT:
            this->eventHandler->nextEventClicked();
            break;
        case PREVIOUS:
            this->eventHandler->previousEventClicked();
            break;
        case LABEL:
            this->eventHandler->labelClicked();
            break;
    }
}

template<> void Event::eventPassArg<double>(double volumeChanged) {
    this->eventHandler->sliderValueChanged(volumeChanged);
}

template<> void Event::eventPassArg<int>(int optionsChoosen){
    this->eventHandler->menubarClicked(optionsChoosen);
}

template<> void Event::eventPassArg<std::string, std::string>(std::string newName, std::string newLink) {
    this->eventHandler->updateFile(newName,newLink);
}