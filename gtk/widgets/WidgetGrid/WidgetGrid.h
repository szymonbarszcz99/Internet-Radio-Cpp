#ifndef UNTITLED2_WIDGETGRID_H
#define UNTITLED2_WIDGETGRID_H
#include "../StationName/StationName.h"
#include "../Buttons/ButtonsAll.h"

class WidgetGrid : public Gtk::Grid{
    ButtonsAll* buttonsAllVector;
    StationName* label;
public:
    WidgetGrid();
    ButtonsAll* getButtonsAllVector();
    StationName* getStationName();
};


#endif //UNTITLED2_WIDGETGRID_H
