#ifndef UNTITLED2_POPUPWINDOW_H
#define UNTITLED2_POPUPWINDOW_H
#include <gtkmm/window.h>
#include <gtkmm/grid.h>

class PopUpWindow : public Gtk::Window{
    Gtk::Grid* grid;
public:
    PopUpWindow(std::string windowName): Gtk::Window(){
        this->grid = new Gtk::Grid();
        this->add(*this->grid);
        this->set_title(windowName);
    };
    void populate(Gtk::Widget* widget, int left, int top, int width = 1);
};


#endif //UNTITLED2_POPUPWINDOW_H
