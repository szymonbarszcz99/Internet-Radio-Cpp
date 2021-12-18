#include "EventHandler.h"

void EventHandler::setStrategy(const std::shared_ptr<ClickedStrategy>& clickedStrategyArg) {
    clickedStrategy = clickedStrategyArg;
}

void EventHandler::executeStrategy(){
    auto sp = this->clickedStrategy.lock();
    sp->onClickedEvent();
}


