#ifndef UNTITLED2_APPWINDOW_H
#define UNTITLED2_APPWINDOW_H
#include <gtkmm/applicationwindow.h>
#include <gtkmm/menubar.h>
#include <gtkmm/toolbar.h>
#include "AppWindowInterface.h"
#include "../EventHandler.h"
#include "widgets/WidgetGrid/WidgetGrid.h"
#include "widgets/AppButton/AppButton.h"
#include "widgets/AppWidget/AppWidget.h"
#include "widgets/AppLabel/AppLabel.h"
#include "widgets/WidgetConstructor/ButtonConstructor.h"
#include "widgets/WidgetConstructor/LabelConstructor.h"
#include "widgets/Buttons/Events/EventClicked.h"
#include "widgets/AppSlider/AppSlider.h"
#include "widgets/Buttons/Events/EventValueChanged.h"


class AppWindow : public AppWindowInterface, public Gtk::ApplicationWindow{
    WidgetGrid* grid;
    AppWidget* appLabel, *playButton1, *pauseButton1, *nextButton, *previousButton, *appSlider;
    Event* eventForWidgets;
    EventValueChanged* eventForSlider;
    Gtk::Box* toolBar;
    Gtk::Menu* menu;
    Gtk::MenuButton* menuButton;
public:
    AppWindow(EventHandler* eventHandler);
    void updateLabel(const std::string& newStation) override;
    AppWindow* createButtons();
    AppWindow* createLabel();
    AppWindow* attachWidgets();
    AppWindow* createSlider();
    AppWindow* createToolbar();
};


#endif //UNTITLED2_APPWINDOW_H
