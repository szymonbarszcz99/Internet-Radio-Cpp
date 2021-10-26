#ifndef UNTITLED2_POPUPWINDOW_H
#define UNTITLED2_POPUPWINDOW_H
#include <gtkmm/window.h>
#include <gtkmm/grid.h>
#include <gtkmm/label.h>

class PopUpWindow : public Gtk::Window{
protected:
    Gtk::Grid* grid;
public:
    void populate(Gtk::Widget* widget, int left, int top, int width = 1);
    PopUpWindow(std::string title): Gtk::Window(){
        this->set_title(title);

        this->grid = new Gtk::Grid();
        this->grid->set_column_spacing(10);
        this->grid->set_row_spacing(10);
        this->grid->property_margin()=10;
        this->add(*grid);
    }
};


#endif //UNTITLED2_POPUPWINDOW_H
