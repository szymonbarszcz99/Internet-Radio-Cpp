#ifndef UNTITLED2_POPUPWINDOWWRITE_H
#define UNTITLED2_POPUPWINDOWWRITE_H
#include <gtkmm/entry.h>
#include <gtkmm/button.h>
#include <iostream>
#include "../widgets/Buttons/Events/Event.h"
#include "PopUpWindow.h"

class PopUpWindowWrite : public PopUpWindow{
    Gtk::Entry* nameEntry, *linkEntry;
    Gtk::Button *addButton;
    Event* event;
    Purpose windowPurpose;
public:
    PopUpWindowWrite(std::string windowName,std::string nameEntry, std::string linkEntry, Event* event): PopUpWindow(windowName), event(event){
        if(nameEntry == "" && linkEntry == "")this->windowPurpose = ADD;
        else this->windowPurpose = UPDATE;

        this->nameEntry = new Gtk::Entry();
        this->nameEntry->set_text(nameEntry);
        this->linkEntry = new Gtk::Entry();
        this->linkEntry->set_text(linkEntry);

        this->addButton = new Gtk::Button();
        if(this->windowPurpose == UPDATE)this->addButton->set_label("Update");
        else this->addButton->set_label("Add");
        this->addButton->signal_clicked().connect(sigc::mem_fun(*this, &PopUpWindowWrite::onAddClicked));

        populate();
    };
    void populate();
    void onAddClicked();
};


#endif //UNTITLED2_POPUPWINDOWWRITE_H
