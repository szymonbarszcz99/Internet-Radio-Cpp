#include "WidgetGrid.h"

WidgetGrid::WidgetGrid():Gtk::Grid() {
    StationName* stationName = new StationName();
    attach(*stationName,0,0);
}