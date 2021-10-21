#ifndef UNTITLED2_MENUBAR_H
#define UNTITLED2_MENUBAR_H
#include <gtkmm/box.h>
#include "FileMenuButton.h"

class Menubar : public Gtk::Box{
    FileMenuButton* fileMenuButton;
public:
    Menubar();
    void createFileMenuButton(EventValueChanged* eventValueChanged);
};


#endif //UNTITLED2_MENUBAR_H
