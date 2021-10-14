#include <iostream>
#include "RadioApp.h"

RadioApp::RadioApp(): Gtk::Application("org.radio") {}

Glib::RefPtr<RadioApp> RadioApp::create() {
    return Glib::RefPtr<RadioApp>(new RadioApp());
}

void RadioApp::createAppWindow() {
    this->appWindow = new AppWindow();
    add_window(*this->appWindow);

    this->appWindow->signal_hide().connect(sigc::mem_fun(*this,&RadioApp::on_hide_window));
}

void RadioApp::on_activate(){
    createAppWindow();
    this->appWindow->present();
    this->guiEventHandler->connectCreatedWindow(this->appWindow);
    this->guiEventHandler->setStationNameOnStartup();
    setButtonCallbacks();
}

void RadioApp::on_hide_window() {
    delete this->appWindow;
}

void RadioApp::setHandler(GuiEventHandler* guiEventHandler1) {
    this->guiEventHandler = guiEventHandler1;
}

void RadioApp::setButtonCallbacks() {
    std::vector<Gtk::Button*> buttonsCallbacks = this->appWindow->getGrid()->getButtonsAllVector()->getVector();

    buttonsCallbacks[0]->signal_clicked().connect(sigc::mem_fun(this->guiEventHandler,&GuiEventHandler::onPreviousClicked));
    buttonsCallbacks[1]->signal_clicked().connect(sigc::mem_fun(this->guiEventHandler,&GuiEventHandler::onPlayClicked));
    buttonsCallbacks[2]->signal_clicked().connect(sigc::mem_fun(this->guiEventHandler,&GuiEventHandler::onPauseClicked));
    buttonsCallbacks[3]->signal_clicked().connect(sigc::mem_fun(this->guiEventHandler,&GuiEventHandler::onNextClicked));
}

AppWindow *RadioApp::getAppWindow() {
    return this->appWindow;
}
