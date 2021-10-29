#ifndef UNTITLED2_VIEWSTATIONSBUTTON_H
#define UNTITLED2_VIEWSTATIONSBUTTON_H
#include <gtkmm/menu.h>
#include <gtkmm/menubutton.h>
#include "../Events/Event.h"

class ViewStationsButton : public Gtk::MenuItem{

    std::shared_ptr<Event> properEvent;
    std::unique_ptr<Gtk::Menu> viewMenu;
    std::unique_ptr<Gtk::MenuItem> menuItem;
    void onValueChosen(Actions actionId);

public:
    ViewStationsButton(std::shared_ptr<Event> properEvent);
    ~ViewStationsButton() override{
        std::cout<<"ViewStationsButton destructor"<<std::endl;
    }
};


#endif //UNTITLED2_VIEWSTATIONSBUTTON_H
