#ifndef UNTITLED2_APPWINDOW_H
#define UNTITLED2_APPWINDOW_H
#include <gtkmm/applicationwindow.h>
#include "AppWindowInterface.h"
#include "../EventHandler.h"
#include "widgets/WidgetGrid/WidgetGrid.h"
#include "widgets/AppButton/AppButton.h"
#include "widgets/AppSlider/AppSlider.h"
#include "widgets/Menubar/Menubar.h"
#include "PopUpWindow/PopUpWindowView.h"
#include "PopUpWindow/PopUpWindowWrite.h"

class AppWindow : public AppWindowInterface, public Gtk::ApplicationWindow{
    WidgetGrid* grid;
    Gtk::Label* label;
    AppButton* playButton1, *pauseButton1, *nextButton, *previousButton;
    AppSlider *appSlider;
    Event* eventForWidgets;
    Menubar* menubar;
    PopUpWindowView* popUpWindowView;
    PopUpWindowWrite* popUpWindow2;

public:
    AppWindow(EventHandler* eventHandler);
    void updateLabel(const std::string& newStation) override;
    AppWindow* createButtons();
    AppWindow* createLabel();
    AppWindow* attachWidgets();
    AppWindow* createSlider();
    AppWindow* createMenubar();
    void createPopUpWindowView(const std::vector<Stations>& stations) override;
    void createPopUpWindowWrite(std::string nameEntry = "", std::string linkEntry = "") override;
};


#endif //UNTITLED2_APPWINDOW_H
