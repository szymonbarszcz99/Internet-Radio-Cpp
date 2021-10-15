#ifndef UNTITLED2_APPWINDOW_H
#define UNTITLED2_APPWINDOW_H
#include <gtkmm/applicationwindow.h>
#include "AppWindowInterface.h"
#include "../EventHandler.h"
#include "widgets/Buttons/ButtonFactory/ButtonFactory.h"
#include "widgets/StationName/StationName.h"
#include "widgets/WidgetGrid/WidgetGrid.h"
#include "widgets/Buttons/Events/EventClicked.h"

class AppWindow : public AppWindowInterface, public Gtk::ApplicationWindow{
    WidgetGrid* grid;
    StationName* stationName;
    ButtonFactory* playButton, *pauseButton, *nextButton, *previousButton;
public:
    AppWindow(EventHandler* eventHandler);
    void updateLabel(const std::string& newStation) override;
};


#endif //UNTITLED2_APPWINDOW_H
