#include <iostream>
#include "RadioApp.h"

RadioApp::RadioApp(): Gtk::Application("org.radio") {}

Glib::RefPtr<RadioApp> RadioApp::create() {
    return Glib::RefPtr<RadioApp>(new RadioApp());
}

void RadioApp::createAppWindow() {
    this->appWindow = new AppWindow(this->eventHandler, this->clickedStrategy,
                                    this->menubarClickedStrategy, this->popUpWindowStrategy,
                                    this->sliderStrategy);
    add_window(*this->appWindow);

    this->appWindow->signal_hide().connect(sigc::mem_fun(*this,&RadioApp::on_hide_window));
}

void RadioApp::on_activate(){
    createAppWindow();
    this->clickedStrategy->setAppWindowInterface(this->appWindow);
    this->menubarClickedStrategy->setAppWindowInterface(this->appWindow);
    this->popUpWindowStrategy->setAppWindowInterface(this->appWindow);
    this->appWindow->present();
}

void RadioApp::on_hide_window() {
    delete this->appWindow;
}

void RadioApp::setEventHandler(EventHandler *eventHandler) {
    this->eventHandler = eventHandler;
}

RadioApp* RadioApp::setPlayerClickedStrategy(PlayerClickedStrategy *clickedStrategy) {
    this->clickedStrategy = clickedStrategy;
    return this;
}

RadioApp* RadioApp::setMenubarClickedStrategy(MenubarClickedStrategy *menubarClickedStrategy) {
    this->menubarClickedStrategy = menubarClickedStrategy;
    return this;
}

RadioApp* RadioApp::setPopUpWindowStrategy(PopUpWindowStrategy *popUpWindowStrategy) {
    this->popUpWindowStrategy = popUpWindowStrategy;
    return this;
}

RadioApp* RadioApp::setSliderStrategy(SliderStrategy* sliderStrategy){
    this->sliderStrategy = sliderStrategy;
    return this;
}

