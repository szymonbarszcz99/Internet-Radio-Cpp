#ifndef UNTITLED2_APPWINDOW_H
#define UNTITLED2_APPWINDOW_H
#include "widgets/WidgetGrid/WidgetGrid.h"
#include "AppWindowInterface.h"

class AppWindow : public Gtk::ApplicationWindow, AppWindowInterface{
    WidgetGrid* grid;
    void attachGrid();
public:
    AppWindow();
};


#endif //UNTITLED2_APPWINDOW_H
