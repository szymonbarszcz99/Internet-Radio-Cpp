#ifndef UNTITLED2_MENUBARCLICKEDSTRATEGY_H
#define UNTITLED2_MENUBARCLICKEDSTRATEGY_H
#pragma once
#include <gtkmm/textbuffer.h>
#include "../bluetooth/Bluetooth.h"
#include "ClickedStrategy.h"
#include "../gtk/PopUpWindow/BtWindow.h"
#include "../gtk/PopUpWindow/HelpWindow.h"
#include <thread>

class MenubarClickedStrategy : public ClickedStrategy{
public:
    void onClickedEvent() override;
    Actions actionToDo;
    const std::string tuneInInstruction = "To get station from TuneIn, open developer tools in your browser and navigate to network tab.\nThen play your stream and look for media with link in its name";
    const std::string fileInstruction = "stations.csv file must contain only two fields separated by comma and newline at the end of single entry.\nThe first field is for station name, and the second for link to stream.\nText cannot include additional commas\nAlso these two fields shouldn't be empty.\nAfter creating the file, place it in your catalog with radio and it will be parsed.";

    ~MenubarClickedStrategy() override{
        std::cout<<"Menubar Strategy destructor"<<std::endl;
    }
};


#endif //UNTITLED2_MENUBARCLICKEDSTRATEGY_H
