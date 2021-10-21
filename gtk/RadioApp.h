#ifndef UNTITLED2_RADIOAPP_H
#define UNTITLED2_RADIOAPP_H
#include <gtkmm.h>
#include "AppWindow.h"
#include "../EventHandler.h"

class RadioApp : public Gtk::Application{
private:
    RadioApp();
    void on_activate() override;
    void createAppWindow();
    void on_hide_window();
    EventHandler* eventHandler = nullptr;
    AppWindow* appWindow = nullptr;

public:
    static Glib::RefPtr<RadioApp> create();
    void setEventHandler(EventHandler* eventHandler);
    AppWindow* getAppWindow();
};


#endif //UNTITLED2_RADIOAPP_H
