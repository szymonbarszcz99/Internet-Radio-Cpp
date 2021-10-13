#ifndef UNTITLED2_WIDGETGRID_H
#define UNTITLED2_WIDGETGRID_H
#include "../StationName/StationName.h"
#include "../Buttons/ButtonsAll.h"

class WidgetGrid : public Gtk::Grid{
public:
    WidgetGrid();
    void changeText(const std::string& newText);
};


#endif //UNTITLED2_WIDGETGRID_H
