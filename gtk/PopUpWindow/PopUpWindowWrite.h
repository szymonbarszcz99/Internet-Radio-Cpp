#ifndef UNTITLED2_POPUPWINDOWWRITE_H
#define UNTITLED2_POPUPWINDOWWRITE_H
#include <gtkmm/entry.h>
#include <gtkmm/button.h>
#include <iostream>
#include "../widgets/Events/Event.h"
#include "PopUpWindow.h"

class PopUpWindowWrite : public PopUpWindow{

    Gtk::Button *addButton;
    const Event& event;
    Actions windowAction;
    std::vector<std::unique_ptr<Gtk::Entry>> entryVec;
public:
    PopUpWindowWrite(std::string windowName,std::string nameEntry, std::string linkEntry, const Event& event,
                     Actions action):
    PopUpWindow(windowName), event(event), windowAction(action){

        this->entryVec.emplace_back(std::make_unique<Gtk::Entry>());
        this->entryVec.back()->set_text(nameEntry);
        this->entryVec.emplace_back(std::make_unique<Gtk::Entry>());
        this->entryVec.back()->set_text(linkEntry);

        this->addButton = new Gtk::Button();
        if(this->windowAction == MODIFY_STATION)this->addButton->set_label("Update");
        else this->addButton->set_label("Add");
        this->addButton->signal_clicked().connect(sigc::mem_fun(*this, &PopUpWindowWrite::onAddClicked));

        populate();
    };
    void populate();
    void onAddClicked();
    ~PopUpWindowWrite() override{
        std::cout<<"Pop Up Window Write destructor"<<std::endl;
    }
};


#endif //UNTITLED2_POPUPWINDOWWRITE_H
