#ifndef UNTITLED2_RADIOAPP_H
#define UNTITLED2_RADIOAPP_H
#include <gtkmm.h>
#include "AppWindow.h"
#include "../EventHandler.h"

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
