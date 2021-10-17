#ifndef UNTITLED2_APPWINDOW_H
#define UNTITLED2_APPWINDOW_H
#include <gtkmm/applicationwindow.h>
#include "AppWindowInterface.h"
#include "../EventHandler.h"
#include "widgets/WidgetGrid/WidgetGrid.h"
#include "widgets/AppButton/AppButton.h"
#include "widgets/AppWidget/AppWidget.h"
#include "widgets/AppLabel/AppLabel.h"

class AppWindow : public AppWindowInterface, public Gtk::ApplicationWindow{
    WidgetGrid* grid;
    AppWidget* appLabel, *playButton1, *pauseButton1;
public:
    AppWindow(EventHandler* eventHandler);
    void updateLabel(const std::string& newStation) override;
};


#endif //UNTITLED2_APPWINDOW_H
