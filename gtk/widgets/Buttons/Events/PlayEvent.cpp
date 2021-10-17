#include "PlayEvent.h"

PlayEvent::PlayEvent(EventHandler *eventHandler): eventHandler(eventHandler) {}

void PlayEvent::Clicked() {
    this->eventHandler->playEventClicked();
}