#ifndef UNTITLED2_POPUPWINDOWWRITE_H
#define UNTITLED2_POPUPWINDOWWRITE_H
#pragma once
#include <gtkmm/entry.h>
#include <gtkmm/button.h>
#include <iostream>
#include <utility>
#include "PopUpWindow.h"

class PopUpWindowWrite : public PopUpWindow{

    Gtk::Button *addButton;
    const Event& event;
    Actions windowAction;
    std::array<std::unique_ptr<Gtk::Entry>,2> entryArr;
public:
    PopUpWindowWrite(const std::string& windowName,const std::string& nameEntry, const std::string& linkEntry, const Event& event,
                     Actions action):
    PopUpWindow(windowName), event(event), windowAction(action){

        this->entryArr[0] = std::make_unique<Gtk::Entry>();
        this->entryArr[0]->set_text(nameEntry);
        this->entryArr[1] = std::make_unique<Gtk::Entry>();
        this->entryArr[1]->set_text(linkEntry);

        this->addButton = new Gtk::Button();
        if(this->windowAction == MODIFY_STATION)this->addButton->set_label("Save");
        else this->addButton->set_label("Add");
        this->addButton->signal_clicked().connect(sigc::mem_fun(*this, &PopUpWindowWrite::onAddClicked));

        this->maximize();
        populate();
    };
    void populate();
    void onAddClicked();
    ~PopUpWindowWrite() override{
        std::cout<<"Pop Up Window Write destructor"<<std::endl;
    }
};


#endif //UNTITLED2_POPUPWINDOWWRITE_H
