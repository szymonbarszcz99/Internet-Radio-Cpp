#include "EventHandler.h"

void EventHandler::setStrategy(const std::shared_ptr<ClickedStrategy>& clickedStrategy) {
    this->clickedStrategy = clickedStrategy;
}

void EventHandler::executeStrategy(){
    auto sp = this->clickedStrategy.lock();
    sp->onClickedEvent();
}


