#ifndef UNTITLED2_MENUBAR_H
#define UNTITLED2_MENUBAR_H
#include <gtkmm/menubar.h>
#include "FileMenuButton.h"
#include "ViewStationsButton.h"

class Menubar : public Gtk::MenuBar{
    std::unique_ptr<FileMenuButton> fileMenuButton;
    std::unique_ptr<ViewStationsButton> viewStationsButton;
public:
    explicit Menubar(std::shared_ptr<Event> event);
    void createFileMenuButton(std::shared_ptr<Event> eventValueChanged);
    void createViewStationButton(std::shared_ptr<Event> event);
};


#endif //UNTITLED2_MENUBAR_H
