#ifndef UNTITLED2_HELPMENUBUTTON_H
#define UNTITLED2_HELPMENUBUTTON_H
#include <gtkmm/menuitem.h>
#include <gtkmm/menu.h>
#include "../Events/Event.h"

class HelpMenuButton : public Gtk::MenuItem{
    const Event& eventValueChanged;
    std::unique_ptr<Gtk::Menu> HelpMenu;
    void onValueChosen(Actions actionId);
    std::array<Gtk::MenuItem,2> optionsVector;
public:
    HelpMenuButton(const Event& eventValueChanged);
    ~HelpMenuButton() override{
        std::cout<<"HelpMenuButton destructor"<<std::endl;
    }
};


#endif //UNTITLED2_HELPMENUBUTTON_H
