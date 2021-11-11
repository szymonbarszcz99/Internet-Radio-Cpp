#ifndef UNTITLED2_APPWINDOW_H
#define UNTITLED2_APPWINDOW_H
#include <gtkmm/applicationwindow.h>
#include <gtkmm/messagedialog.h>
#include "AppWindowInterface.h"
#include "../EventHandler.h"
#include "widgets/AppButton/AppButton.h"
#include "widgets/AppSlider/AppSlider.h"
#include "widgets/Menubar/Menubar.h"
#include "PopUpWindow/PopUpWindowView.h"
#include "PopUpWindow/PopUpWindowWrite.h"

class AppWindow : public AppWindowInterface, public Gtk::ApplicationWindow{
    std::unique_ptr<Gtk::Grid> grid;
    std::unique_ptr<AppButton> playButton1, pauseButton1, nextButton, previousButton;
    std::unique_ptr<AppSlider> appSlider;
    std::unique_ptr<Gtk::Label> label,songNameLabel;
    std::shared_ptr<Event> eventForWidgets;
    std::unique_ptr<Menubar> menubar;
    std::unique_ptr<PopUpWindowView> popUpWindowView;
    std::unique_ptr<PopUpWindowWrite> popUpWindow2;

public:
    AppWindow(std::shared_ptr<EventHandler>&& eventHandler,std::shared_ptr<PlayerClickedStrategy> clickedStrategy,
              std::shared_ptr<MenubarClickedStrategy> menubarClickedStrategy, std::shared_ptr<PopUpWindowStrategy> popUpWindowStrategy,
              std::shared_ptr<SliderStrategy> sliderStrategy,std::shared_ptr<StartupStrategy> startupStrategy);
    void updateLabel(const std::string& newStation) override;
    void updateSongNameLabel(const std::string& songName) override;
    AppWindow* createButtons();
    AppWindow* createLabel();
    AppWindow* attachWidgets();
    AppWindow* createSlider();
    AppWindow* createMenubar();
    void createPopUpWindowView(const std::vector<Stations>& stations) override;
    void createPopUpWindowWrite(std::string windowName,std::string nameEntry = "", std::string linkEntry = "") override;
    ~AppWindow() override;
    void throwModal(int lineNumber,std::string text) override;
    void startupCheck();
};


#endif //UNTITLED2_APPWINDOW_H
