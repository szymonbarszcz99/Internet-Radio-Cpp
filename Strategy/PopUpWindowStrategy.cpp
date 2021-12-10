#include "PopUpWindowStrategy.h"

void PopUpWindowStrategy::onClickedEvent() {
    auto lsp = linksInterface.lock();
    auto wsp = appWindowInterface.lock();
    if(actionToDo == ADD_STATION) {
        possibleErrors appendError = lsp->appendStation(name, link);
        if (appendError != VALID) {
            throwModalOnAppWindow(appendError);
        }
        else{
            wsp->closeWindow();
        }
    }
    else{
        possibleErrors modifyError = lsp->modifyStation(name,link);
        if(modifyError == VALID){
            wsp->updateLabel(name);
            wsp->closeWindow();
        }
        else{
            throwModalOnAppWindow(modifyError);
        }
    }
}

void PopUpWindowStrategy::throwModalOnAppWindow(possibleErrors error) const{
    auto wsp = appWindowInterface.lock();
    switch (error) {
        case COMMA:
            wsp->throwModal(-1, "Text should not contain commas");
            break;
        case NON_ASCII:
            wsp->throwModal(-1, "Text should not contain\nnon ASCII characters");
            break;
        case EMPTY:
            wsp->throwModal(-1, "Text should not be empty");
            break;
    }
}




