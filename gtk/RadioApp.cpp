#include <iostream>
#include "RadioApp.h"

RadioApp::RadioApp(const Event& event): Gtk::Application("org.radio") {
    this->appWindow = std::make_shared<AppWindow>(event);
}

Glib::RefPtr<RadioApp> RadioApp::create(const Event& event) {
    return Glib::RefPtr<RadioApp>(new RadioApp(event));
}

void RadioApp::on_activate(){

    add_window(*this->appWindow);

    this->appWindow->signal_hide().connect(sigc::mem_fun(*this,&RadioApp::on_hide_window));
    ClickedStrategy::appWindowInterface = this->appWindow;
    this->appWindow->show_all();
    this->appWindow->startupCheckLinks();
}

void RadioApp::on_hide_window() {
    std::cout<<"Hide window"<<std::endl;
    this->appWindow->hide();
}

RadioApp::~RadioApp() {
    std::cout<<"RadioApp destructor"<<std::endl;
    std::cout<<"App window use count: "<<this->appWindow.use_count()<<std::endl;
}


