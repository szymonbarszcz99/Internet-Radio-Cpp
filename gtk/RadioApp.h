#ifndef UNTITLED2_RADIOAPP_H
#define UNTITLED2_RADIOAPP_H
#include "AppWindow.h"

class RadioApp : public Gtk::Application {
private:
    AppWindow* appWindow;
    RadioApp();
    void on_activate() override;
    void createAppWindow();
    void on_hide_window();

public:
    static Glib::RefPtr<RadioApp> create();
};


#endif //UNTITLED2_RADIOAPP_H
