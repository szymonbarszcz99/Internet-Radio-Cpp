#include <iostream>
#include "RadioApp.h"

RadioApp::RadioApp(): Gtk::Application("org.radio") {}

Glib::RefPtr<RadioApp> RadioApp::create() {
    return Glib::RefPtr<RadioApp>(new RadioApp());
}

void RadioApp::createAppWindow() {
    this->appWindow = std::make_shared<AppWindow>(std::move(this->eventHandler), this->playerClickedStrategy,
                                    this->menubarClickedStrategy, this->popUpWindowStrategy,
                                    this->sliderStrategy,this->startupStrategy);
    add_window(*this->appWindow);

    this->appWindow->signal_hide().connect(sigc::mem_fun(*this,&RadioApp::on_hide_window));
}

void RadioApp::on_activate(){
    createAppWindow();
    this->menubarClickedStrategy->setAppWindowInterface(this->appWindow);
    this->popUpWindowStrategy->setAppWindowInterface(this->appWindow);
    this->playerClickedStrategy->setAppWindowInterface(this->appWindow);
    this->startupStrategy->setAppWindowInterface(this->appWindow);
    this->busMessageStrategy->setAppWindowInterface(this->appWindow);
    this->appWindow->present();
    this->appWindow->startupCheck();
}

void RadioApp::on_hide_window() {
    //std::cout<<"Hide window"<<std::endl;
    this->appWindow->hide();
}

void RadioApp::setEventHandler(std::shared_ptr<EventHandler> eventHandler) {
    this->eventHandler = eventHandler;
}

RadioApp* RadioApp::setPlayerClickedStrategy(std::shared_ptr<PlayerClickedStrategy>&& clickedStrategy) {
    this->playerClickedStrategy = clickedStrategy;
    return this;
}

RadioApp* RadioApp::setMenubarClickedStrategy(std::shared_ptr<MenubarClickedStrategy>&& menubarClickedStrategy) {
    this->menubarClickedStrategy = menubarClickedStrategy;
    return this;
}

RadioApp* RadioApp::setPopUpWindowStrategy(std::shared_ptr<PopUpWindowStrategy>&& popUpWindowStrategy) {
    this->popUpWindowStrategy = popUpWindowStrategy;
    return this;
}

RadioApp* RadioApp::setSliderStrategy(std::shared_ptr<SliderStrategy>&& sliderStrategy){
    this->sliderStrategy = sliderStrategy;
    return this;
}

RadioApp::~RadioApp() {
    std::cout<<"RadioApp destructor"<<std::endl;
    std::cout<<"App window use count: "<<this->appWindow.use_count()<<std::endl;
}

RadioApp *RadioApp::setStartupStrategy(std::shared_ptr<StartupStrategy> &&startupStrategy) {
    this->startupStrategy = startupStrategy;
    return this;
}

RadioApp *RadioApp::setBusMessageStrategy(std::shared_ptr<BusMessageStrategy> &&busMessageStrategy) {
    this->busMessageStrategy = busMessageStrategy;
    return this;
}


