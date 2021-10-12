#ifndef UNTITLED2_BUTTONSALL_H
#define UNTITLED2_BUTTONSALL_H
#include <vector>
#include "ButtonFactory/ButtonFactory.h"

class ButtonsAll{
    std::vector<Gtk::Button*> ButtonVector;
public:
    ButtonsAll();
    const std::vector<Gtk::Button*>& getVector();
};


#endif //UNTITLED2_BUTTONSALL_H
