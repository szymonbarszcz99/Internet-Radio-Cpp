#ifndef UNTITLED2_MENUBAR_H
#define UNTITLED2_MENUBAR_H
#include <gtkmm/menubar.h>
#include "FileMenuButton.h"
#include "ViewStationsButton.h"

class Menubar : public Gtk::MenuBar{
    FileMenuButton* fileMenuButton;
    ViewStationsButton* viewStationsButton;
public:
    Menubar(Event* event);
    void createFileMenuButton(Event* eventValueChanged);
    void createViewStationButton(Event* event);
};


#endif //UNTITLED2_MENUBAR_H
