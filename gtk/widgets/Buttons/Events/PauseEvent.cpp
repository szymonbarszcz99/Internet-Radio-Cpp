#include "PauseEvent.h"

PauseEvent::PauseEvent(EventHandler *eventHandler): eventHandler(eventHandler) {}

void PauseEvent::Clicked() {
    this->eventHandler->pauseEventClicked();
}