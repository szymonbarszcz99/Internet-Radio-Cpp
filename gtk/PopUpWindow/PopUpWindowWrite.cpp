#include "PopUpWindowWrite.h"

void PopUpWindowWrite::populate() {

    Gtk::Label* name = new Gtk::Label("Name");
    PopUpWindow::populate(name,0,0);
    this->grid->attach(*entryArr[0],0,1);

    Gtk::Label* link = new Gtk::Label("Link");
    PopUpWindow::populate(link,0,2);
    this->grid->attach(*entryArr[1],0,3);

    PopUpWindow::populate(addButton,0,4);

    this->show_all();
}

void PopUpWindowWrite::onAddClicked() {
    this->event.eventPassArg(std::string(entryArr[0]->get_text()),
                              std::string(entryArr[1]->get_text()),
                              this->windowAction);
}
