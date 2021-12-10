#ifndef UNTITLED2_RADIOAPP_H
#define UNTITLED2_RADIOAPP_H
#pragma once
#include <iostream>
#include <gtkmm.h>
#include "AppWindow.h"

class RadioApp : public Gtk::Application{
private:
    RadioApp(const Event& event);
    void on_activate() override;
    void on_hide_window();
    std::shared_ptr<AppWindow> appWindow;

public:
    static Glib::RefPtr<RadioApp> create(const Event& event);
    ~RadioApp() override;
};


#endif //UNTITLED2_RADIOAPP_H
