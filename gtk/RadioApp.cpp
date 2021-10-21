#include <iostream>
#include "RadioApp.h"

RadioApp::RadioApp(): Gtk::Application("org.radio") {}

Glib::RefPtr<RadioApp> RadioApp::create() {
    return Glib::RefPtr<RadioApp>(new RadioApp());
}

void RadioApp::createAppWindow() {
    this->appWindow = new AppWindow(this->eventHandler);
    add_window(*this->appWindow);

    this->appWindow->signal_hide().connect(sigc::mem_fun(*this,&RadioApp::on_hide_window));
}

void RadioApp::on_activate(){
    createAppWindow();
    this->eventHandler->setAppWindowInterface(this->appWindow);
    this->appWindow->present();
}

void RadioApp::on_hide_window() {
    delete this->appWindow;
}

AppWindow *RadioApp::getAppWindow() {
    return this->appWindow;
}

void RadioApp::setEventHandler(EventHandler *eventHandler) {
    this->eventHandler = eventHandler;
}


