#include "RadioApp.h"

RadioApp::RadioApp(): Gtk::Application("org.radio") {}

Glib::RefPtr<RadioApp> RadioApp::create() {
    return Glib::RefPtr<RadioApp>(new RadioApp());
}

AppWindow* RadioApp::createAppWindow() {
    AppWindow* appWindow = new AppWindow();
    add_window(*appWindow);

    appWindow->signal_hide().connect(sigc::bind<Gtk::Window*>(sigc::mem_fun(*this,&RadioApp::on_hide_window),appWindow));

    return appWindow;
}

void RadioApp::on_activate(){
    AppWindow* appWindow = createAppWindow();
    appWindow->present();
}

void RadioApp::on_hide_window(Gtk::Window *window) {
    delete window;
}