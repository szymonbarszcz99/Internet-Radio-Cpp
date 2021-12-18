#include "MenubarClickedStrategy.h"

void MenubarClickedStrategy::onClickedEvent() {
    std::cout<<"Menubar value: "<<actionToDo<<std::endl;
    auto wsp = MenubarClickedStrategy::appWindowInterface.lock();
    auto lsp = MenubarClickedStrategy::linksInterface.lock();
    auto psp = MenubarClickedStrategy::playerInterface.lock();

    if(actionToDo == ADD_STATION){
        wsp->createPopUpWindowWrite("Add","","");
    }
    else if(actionToDo == DELETE_STATION) {
        lsp->deleteStation();
        lsp->setPreviousStation();
        const Stations& stations = lsp->getCurrentStation();
        wsp->updateLabel(stations.StationName);
        psp->changeStation(stations.StationLink);
    }
    else if(actionToDo == MODIFY_STATION){
        const Stations& stations = lsp->getCurrentStation();
        wsp->createPopUpWindowWrite("Update",stations.StationName, stations.StationLink);
    }
    else if(actionToDo == VIEW_ALL)wsp->createPopUpWindowView(lsp->getAllStations());

    else if(actionToDo == HELP_TUNEIN){
        auto helpWindow = std::make_shared<HelpWindow>();
        helpWindow->setBuffer(tuneInInstruction);
        wsp->showWindow(helpWindow);
    }
    else if(actionToDo == HELP_FILE){
        auto helpWindow = std::make_shared<HelpWindow>();
        helpWindow->setBuffer(fileInstruction);
        wsp->showWindow(helpWindow);
    }
    else if(actionToDo == BT_SCAN){
        auto btWindow = std::make_shared<BtWindow>();
        wsp->showWindow(btWindow);
        std::thread scanningThread([=]{
            Bluetooth bluetooth;
            bluetooth.scan(btWindow->devices);
            btWindow->stopScanning();
        });
        scanningThread.detach();
    }
    else if(actionToDo == BT_DISC){
        std::thread btDisc ([&]{BtWindow::disconnect();});
        btDisc.detach();
    }
}
