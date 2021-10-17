#include "LabelEvent.h"

LabelEvent::LabelEvent(EventHandler *eventHandler):eventHandler(eventHandler) {}

void LabelEvent::Clicked() {
    this->eventHandler->labelClicked();
}