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
    std::shared_ptr<EventHandler> eventHandler;
    std::shared_ptr<AppWindow> appWindow;
    std::shared_ptr<PlayerClickedStrategy> playerClickedStrategy;
    std::shared_ptr<MenubarClickedStrategy> menubarClickedStrategy;
    std::shared_ptr<PopUpWindowStrategy> popUpWindowStrategy;
    std::shared_ptr<SliderStrategy> sliderStrategy;
    std::shared_ptr<StartupStrategy> startupStrategy;
    std::shared_ptr<BusMessageStrategy> busMessageStrategy;

public:
    static Glib::RefPtr<RadioApp> create();
    void setEventHandler(std::shared_ptr<EventHandler> eventHandler);
    RadioApp* setPlayerClickedStrategy(std::shared_ptr<PlayerClickedStrategy>&& clickedStrategy);
    RadioApp* setMenubarClickedStrategy(std::shared_ptr<MenubarClickedStrategy>&& menubarClickedStrategy);
    RadioApp* setPopUpWindowStrategy(std::shared_ptr<PopUpWindowStrategy>&& popUpWindowStrategy);
    RadioApp* setSliderStrategy(std::shared_ptr<SliderStrategy>&& sliderStrategy);
    RadioApp* setStartupStrategy(std::shared_ptr<StartupStrategy>&& startupStrategy);
    RadioApp* setBusMessageStrategy(std::shared_ptr<BusMessageStrategy>&& busMessageStrategy);
    ~RadioApp() override;
};


#endif //UNTITLED2_RADIOAPP_H
