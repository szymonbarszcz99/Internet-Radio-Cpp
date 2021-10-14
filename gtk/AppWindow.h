#ifndef UNTITLED2_APPWINDOW_H
#define UNTITLED2_APPWINDOW_H
#include "AppWindowInterface.h"

class AppWindow : public AppWindowInterface, public Gtk::ApplicationWindow{
    void attachGrid();
    WidgetGrid* grid;
public:
    AppWindow();
    WidgetGrid* getGrid() override;
    void updateLabel(const std::string& newStation) override;
};


#endif //UNTITLED2_APPWINDOW_H
