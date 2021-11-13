#include <iostream>
#include "RadioApp.h"

RadioApp::RadioApp(std::shared_ptr<EventHandler> eventHandler,std::shared_ptr<PlayerClickedStrategy> clickedStrategy,
                   std::shared_ptr<MenubarClickedStrategy> menubarClickedStrategy, std::shared_ptr<PopUpWindowStrategy> popUpWindowStrategy,
                   std::shared_ptr<SliderStrategy> sliderStrategy,std::shared_ptr<StartupStrategy> startupStrategy): Gtk::Application("org.radio") {


    this->appWindow = std::make_shared<AppWindow>(std::move(eventHandler),clickedStrategy,
                                                  menubarClickedStrategy,popUpWindowStrategy,
                                                  sliderStrategy,startupStrategy);
}

Glib::RefPtr<RadioApp> RadioApp::create(std::shared_ptr<EventHandler> eventHandler,std::shared_ptr<PlayerClickedStrategy> clickedStrategy,
                                        std::shared_ptr<MenubarClickedStrategy> menubarClickedStrategy, std::shared_ptr<PopUpWindowStrategy> popUpWindowStrategy,
                                        std::shared_ptr<SliderStrategy> sliderStrategy,std::shared_ptr<StartupStrategy> startupStrategy) {
    return Glib::RefPtr<RadioApp>(new RadioApp(eventHandler,clickedStrategy,menubarClickedStrategy,popUpWindowStrategy,
    sliderStrategy, startupStrategy));
}

void RadioApp::on_activate(){

    add_window(*this->appWindow);

    this->appWindow->signal_hide().connect(sigc::mem_fun(*this,&RadioApp::on_hide_window));
    ClickedStrategy::appWindowInterface = this->appWindow;
    this->appWindow->show_all();
    this->appWindow->startupCheck();
}

void RadioApp::on_hide_window() {
    std::cout<<"Hide window"<<std::endl;
    this->appWindow->hide();
}

RadioApp::~RadioApp() {
    std::cout<<"RadioApp destructor"<<std::endl;
    std::cout<<"App window use count: "<<this->appWindow.use_count()<<std::endl;
}


