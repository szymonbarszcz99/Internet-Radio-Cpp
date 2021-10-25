#ifndef UNTITLED2_POPUPWINDOW2_H
#define UNTITLED2_POPUPWINDOW2_H
#include <gtkmm/window.h>
#include <gtkmm/entry.h>
#include <gtkmm/button.h>
#include <gtkmm/grid.h>
#include <iostream>
#include "../widgets/Buttons/Events/Event.h"

class PopUpWindow2 : public Gtk::Window{
    Gtk::Grid* grid;
    Gtk::Entry* nameEntry, *linkEntry;
    Gtk::Button *addButton;
    Event* event;
public:
    PopUpWindow2(std::string windowName,std::string nameEntry, std::string linkEntry, Event* event): Gtk::Window(), event(event){

        this->grid = new Gtk::Grid();
        this->grid->set_column_spacing(10);
        this->grid->set_row_spacing(10);
        this->grid->property_margin()=10;

        this->add(*this->grid);
        this->set_title(windowName);

        this->nameEntry = new Gtk::Entry();
        this->nameEntry->set_text(nameEntry);
        this->linkEntry = new Gtk::Entry();
        this->linkEntry->set_text(linkEntry);

        this->addButton = new Gtk::Button();
        if(nameEntry != "" && linkEntry != "")this->addButton->set_label("Update");
        else this->addButton->set_label("Add");
        this->addButton->signal_clicked().connect(sigc::mem_fun(*this, &PopUpWindow2::onAddClicked));

        populate();
    };
    void populate();
    void onAddClicked();
};


#endif //UNTITLED2_POPUPWINDOW2_H
