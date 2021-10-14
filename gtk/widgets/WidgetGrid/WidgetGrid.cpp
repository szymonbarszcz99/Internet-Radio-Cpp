#include "WidgetGrid.h"

WidgetGrid::WidgetGrid():Gtk::Grid() {
    this->label = new StationName();
    attach(*this->label,0,0,4);

    int left = 0;
    this->buttonsAllVector = new ButtonsAll();
    for(auto it: buttonsAllVector->getVector()){
        attach(*it,left++,1,1,1);
    }
}

ButtonsAll* WidgetGrid::getButtonsAllVector() {
    return this->buttonsAllVector;
}

StationName* WidgetGrid::getStationName() {
    return this->label;
}