#ifndef UNTITLED2_APPWINDOW_H
#define UNTITLED2_APPWINDOW_H
#pragma once
#include <gtkmm/applicationwindow.h>
#include <gtkmm/messagedialog.h>
#include "AppWindowInterface.h"
#include "PopUpWindow/PopUpWindowWrite.h"
#include "widgets/AppButton/AppButton.h"
#include "widgets/AppSlider/AppSlider.h"
#include "widgets/Menubar/Menubar.h"
#include "PopUpWindow/PopUpWindowView.h"

class AppWindow : public AppWindowInterface, public Gtk::ApplicationWindow{
    std::unique_ptr<Gtk::Grid> grid;
    std::unique_ptr<AppButton> playButton1, pauseButton1, nextButton, previousButton;
    std::unique_ptr<AppSlider> appSlider;
    std::unique_ptr<Gtk::Label> label,songNameLabel;
    const Event& eventForWidgets;
    std::unique_ptr<Menubar> menubar;
    std::unique_ptr<PopUpWindowView> popUpWindowView;
    std::shared_ptr<Gtk::Window> windowToShow;

public:
    AppWindow(const Event& event);
    void updateSongNameLabel(const std::string& songName) override;
    void updateLabel(const std::string& text) override;
    AppWindow* createButtons();
    AppWindow* createLabel();
    AppWindow* attachWidgets();
    AppWindow* createSlider();
    AppWindow* createMenubar();
    void createPopUpWindowView(const std::vector<Stations>& stations) override;
    void createPopUpWindowWrite(std::string windowName,std::string nameEntry = "", std::string linkEntry = "") override;
    ~AppWindow() override;
    void throwModal(int lineNumber,std::string text) override;
    void startupCheckLinks();
    void showWindow(std::shared_ptr<Gtk::Window> windowToShow) override;
    void closeWindow() override;
};


#endif //UNTITLED2_APPWINDOW_H
