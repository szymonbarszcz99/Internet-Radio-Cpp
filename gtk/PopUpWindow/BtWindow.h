#ifndef UNTITLED2_BTWINDOW_H
#define UNTITLED2_BTWINDOW_H
#pragma once
#include <gtkmm/window.h>
#include <gtkmm/label.h>
#include <gtkmm/listviewtext.h>
#include <iostream>

static std::string currentSpeaker;

class BtWindow : public Gtk::Window{
    Gtk::Label label;
    Gtk::ListViewText list{2};
    void on_my_row_activated(const Gtk::TreeModel::Path& path, Gtk::TreeViewColumn* column);


public:
    BtWindow(): Gtk::Window(){
        set_title("Bluetooth devices");
        property_deletable() = false;
        property_resizable() = false;
        property_accept_focus() = false;

        this->label.set_text("Searching devices");
        this->label.property_margin() = 10;

        this->list.set_column_title(0,"Name");
        this->list.set_column_title(1,"Address");
        this->list.property_margin() = 10;

        add(label);
        this->show_all();
    }

    void addList(std::map<std::string, std::string> devices);

    static void disconnect();

};


#endif //UNTITLED2_BTWINDOW_H
