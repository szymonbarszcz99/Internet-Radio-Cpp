#ifndef UNTITLED2_FILEMENUBUTTON_H
#define UNTITLED2_FILEMENUBUTTON_H
#include <gtkmm/menu.h>
#include <gtkmm/menubutton.h>
#include "../Events/Event.h"

class FileMenuButton : public Gtk::MenuItem{
    std::shared_ptr<Event> eventValueChanged;
    void onValueChosen(Actions actionId);
    std::unique_ptr<Gtk::Menu> fileMenu;
    std::vector<std::unique_ptr<Gtk::MenuItem>> optionsVector;
public:
    FileMenuButton(std::shared_ptr<Event> eventValueChanged);
    ~FileMenuButton() override{
        std::cout<<"FileMenuButton destructor"<<std::endl;
    }
};


#endif //UNTITLED2_FILEMENUBUTTON_H
