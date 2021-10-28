#include "EventHandler.h"

void EventHandler::setStrategy(const std::shared_ptr<ClickedStrategy>& clickedStrategy) {
    this->clickedStrategy = clickedStrategy;
}

void EventHandler::executeStrategy() {
    this->clickedStrategy->onClickedEvent();
}


