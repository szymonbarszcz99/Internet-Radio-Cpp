#include "PopUpWindowWrite.h"

void PopUpWindowWrite::populate() {

    Gtk::Label* name = new Gtk::Label("Name");
    PopUpWindow::populate(name,0,0);
    this->grid->attach(*entryVec[0],0,1);

    Gtk::Label* link = new Gtk::Label("Link");
    PopUpWindow::populate(link,0,2);
    this->grid->attach(*entryVec[1],0,3);

    PopUpWindow::populate(addButton,0,4);
}

void PopUpWindowWrite::onAddClicked() {
    this->event.eventPassArg(std::string(entryVec[0]->get_text()),
                              std::string(entryVec[1]->get_text()),
                              this->windowAction);
    this->close();
}
