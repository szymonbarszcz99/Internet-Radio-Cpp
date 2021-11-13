#ifndef UNTITLED2_RADIOAPP_H
#define UNTITLED2_RADIOAPP_H
#include <gtkmm.h>
#include "AppWindow.h"
#include "../EventHandler.h"

class RadioApp : public Gtk::Application{
private:
    RadioApp(std::shared_ptr<EventHandler> eventHandler,std::shared_ptr<PlayerClickedStrategy> clickedStrategy,
             std::shared_ptr<MenubarClickedStrategy> menubarClickedStrategy, std::shared_ptr<PopUpWindowStrategy> popUpWindowStrategy,
             std::shared_ptr<SliderStrategy> sliderStrategy,std::shared_ptr<StartupStrategy> startupStrategy);
    void on_activate() override;
    void on_hide_window();
    std::shared_ptr<AppWindow> appWindow;

public:
    static Glib::RefPtr<RadioApp> create(std::shared_ptr<EventHandler> eventHandler,std::shared_ptr<PlayerClickedStrategy> clickedStrategy,
                                         std::shared_ptr<MenubarClickedStrategy> menubarClickedStrategy, std::shared_ptr<PopUpWindowStrategy> popUpWindowStrategy,
                                         std::shared_ptr<SliderStrategy> sliderStrategy,std::shared_ptr<StartupStrategy> startupStrategy);
    ~RadioApp() override;
};


#endif //UNTITLED2_RADIOAPP_H
