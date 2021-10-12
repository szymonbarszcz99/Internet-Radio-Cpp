#ifndef UNTITLED2_APPWINDOW_H
#define UNTITLED2_APPWINDOW_H
#include "widgets/WidgetGrid/WidgetGrid.h"

class AppWindow : public Gtk::ApplicationWindow{
    WidgetGrid* grid;
    void attachGrid();
public:
    AppWindow();
};


#endif //UNTITLED2_APPWINDOW_H
