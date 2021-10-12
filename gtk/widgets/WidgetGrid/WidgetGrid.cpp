#include "WidgetGrid.h"

WidgetGrid::WidgetGrid():Gtk::Grid() {
    auto stationName = new StationName();
    attach(*stationName,0,0,4);

    int left = 0;
    auto buttonsAll = new ButtonsAll();
    for(auto it: buttonsAll->getVector()){
        attach(*it,left++,1,1,1);
    }
}