#include "EventHandler.h"

void EventHandler::setStrategy(ClickedStrategy *clickedStrategy) {
    this->clickedStrategy = clickedStrategy;
}

void EventHandler::executeStrategy() {
    this->clickedStrategy->onClickedEvent();
}


