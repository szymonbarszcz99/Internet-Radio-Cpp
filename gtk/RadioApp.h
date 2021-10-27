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
    PlayerClickedStrategy* clickedStrategy = nullptr;
    MenubarClickedStrategy* menubarClickedStrategy = nullptr;
    PopUpWindowStrategy* popUpWindowStrategy = nullptr;
    SliderStrategy* sliderStrategy = nullptr;

public:
    static Glib::RefPtr<RadioApp> create();
    void setEventHandler(EventHandler* eventHandler);
    void setPlayerClickedStrategy(PlayerClickedStrategy *clickedStrategy);
    AppWindow* getAppWindow();
    void setMenubarClickedStrategy(MenubarClickedStrategy *menubarClickedStrategy);
    void setPopUpWindowStrategy(PopUpWindowStrategy *popUpWindowStrategy);
    void setSliderStrategy(SliderStrategy *sliderStrategy);
};


#endif //UNTITLED2_RADIOAPP_H
