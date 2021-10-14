#ifndef UNTITLED2_RADIOAPP_H
#define UNTITLED2_RADIOAPP_H
#include "AppWindow.h"
#include "GuiEventHandler.h"

class RadioApp : public Gtk::Application {
private:
    GuiEventHandler* guiEventHandler = nullptr;
    AppWindow* appWindow = nullptr;
    RadioApp();
    void on_activate() override;
    void createAppWindow();
    void on_hide_window();

public:
    static Glib::RefPtr<RadioApp> create();
    void setHandler(GuiEventHandler* guiEventHandler1);
    void setButtonCallbacks();
    AppWindow* getAppWindow();
};


#endif //UNTITLED2_RADIOAPP_H
