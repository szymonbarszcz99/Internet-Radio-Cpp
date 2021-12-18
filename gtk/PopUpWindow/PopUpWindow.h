#ifndef UNTITLED2_POPUPWINDOW_H
#define UNTITLED2_POPUPWINDOW_H
#pragma once
#include <gtkmm/window.h>
#include <gtkmm/grid.h>
#include <gtkmm/label.h>
#include <iostream>
#include "../widgets/Events/Event.h"


class PopUpWindow : public Gtk::Window{
protected:
    std::unique_ptr<Gtk::Grid> grid;
    std::vector<std::unique_ptr<Gtk::Widget>> widgetVec;
    Gtk::ScrolledWindow scrolledWindow;
public:
    void populate(Gtk::Widget* widget, int left, int top, int width = 1);
    explicit PopUpWindow(const std::string& title): Gtk::Window(){
        this->set_title(title);

        this->grid = std::make_unique<Gtk::Grid>();
        this->grid->set_column_spacing(10);
        this->grid->set_row_spacing(10);
        this->grid->property_margin()=10;

        scrolledWindow.add(*grid);
        scrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);
        this->add(scrolledWindow);
    }
    ~PopUpWindow() override{
        std::cout<<"Pop Up Window destructor"<<std::endl;
    };
};


#endif //UNTITLED2_POPUPWINDOW_H
