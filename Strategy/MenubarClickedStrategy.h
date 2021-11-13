#ifndef UNTITLED2_MENUBARCLICKEDSTRATEGY_H
#define UNTITLED2_MENUBARCLICKEDSTRATEGY_H
#include "ClickedStrategy.h"

class MenubarClickedStrategy : public ClickedStrategy{


public:
    void onClickedEvent() override;
    Actions actionToDo;

    ~MenubarClickedStrategy() override{
        std::cout<<"Menubar Strategy destructor"<<std::endl;
    }
};


#endif //UNTITLED2_MENUBARCLICKEDSTRATEGY_H
