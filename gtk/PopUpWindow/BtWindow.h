#ifndef UNTITLED2_BTWINDOW_H
#define UNTITLED2_BTWINDOW_H
#pragma once
#include <iostream>
#include <gtkmm.h>

static std::string currentSpeaker;

class BtWindow : public Gtk::Window{
    Gtk::Label label;
    Gtk::ListViewText list{2};
    Gtk::Box box;
    void on_my_row_activated(const Gtk::TreeModel::Path& path, Gtk::TreeViewColumn* column);
    Glib::Dispatcher dispatcher;

public:
    std::map<std::string, std::string> devices;
    void stopScanning();

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

        this->dispatcher.connect(sigc::mem_fun(*this,&BtWindow::addList));

        add(label);
        this->show_all();
    }

    void addList();

    static void disconnect();

};


#endif //UNTITLED2_BTWINDOW_H
