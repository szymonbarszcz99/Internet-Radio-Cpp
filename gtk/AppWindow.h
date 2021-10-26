#ifndef UNTITLED2_APPWINDOW_H
#define UNTITLED2_APPWINDOW_H
#include <gtkmm/applicationwindow.h>
#include "AppWindowInterface.h"
#include "../EventHandler.h"
#include "widgets/WidgetGrid/WidgetGrid.h"
#include "widgets/AppButton/AppButton.h"
#include "widgets/AppWidget/AppWidget.h"
#include "widgets/AppLabel/AppLabel.h"
#include "widgets/AppSlider/AppSlider.h"
#include "widgets/Menubar/Menubar.h"
#include "PopUpWindow/PopUpWindow.h"
#include "PopUpWindow/PopUpWindow2.h"

class AppWindow : public AppWindowInterface, public Gtk::ApplicationWindow{
    WidgetGrid* grid;
    AppWidget* appLabel, *playButton1, *pauseButton1, *nextButton, *previousButton, *appSlider;
    Event* eventForWidgets;
    Menubar* menubar;
    PopUpWindow* popUpWindow;
    PopUpWindow2* popUpWindow2;

public:
    AppWindow(EventHandler* eventHandler);
    void updateLabel(const std::string& newStation) override;
    AppWindow* createButtons();
    AppWindow* createLabel();
    AppWindow* attachWidgets();
    AppWindow* createSlider();
    AppWindow* createMenubar();
    void createPopUpWindow(const std::vector<Stations>& stations) override;
    void createPopUpWindow2(std::string nameEntry = "", std::string linkEntry = "") override;
};


#endif //UNTITLED2_APPWINDOW_H
