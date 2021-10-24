#ifndef UNTITLED2_POPUPWINDOW2_H
#define UNTITLED2_POPUPWINDOW2_H
#include <gtkmm/window.h>
#include <gtkmm/entry.h>
#include <gtkmm/button.h>
#include <gtkmm/grid.h>
#include <iostream>

class PopUpWindow2 : public Gtk::Window{
    Gtk::Grid* grid;
    Gtk::Entry* nameEntry, *linkEntry;
    Gtk::Button *addButton;
public:
    PopUpWindow2(std::string windowName): Gtk::Window(){

        this->grid = new Gtk::Grid();
        this->grid->set_column_spacing(10);
        this->grid->set_row_spacing(10);
        this->grid->property_margin()=10;

        this->add(*this->grid);
        this->set_title(windowName);

        this->addButton = new Gtk::Button("Add");
        this->addButton->signal_clicked().connect(sigc::mem_fun(*this, &PopUpWindow2::onAddClicked));

        populate();
    };
    void populate();
    void onAddClicked();
};


#endif //UNTITLED2_POPUPWINDOW2_H
