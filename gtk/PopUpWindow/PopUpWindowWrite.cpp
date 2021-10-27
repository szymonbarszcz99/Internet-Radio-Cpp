#include "PopUpWindowWrite.h"

void PopUpWindowWrite::populate() {

    Gtk::Label* name = new Gtk::Label("Name");
    PopUpWindow::populate(name,0,0);
    PopUpWindow::populate(nameEntry,0,1);

    Gtk::Label* link = new Gtk::Label("Link");
    PopUpWindow::populate(link,0,2);
    PopUpWindow::populate(linkEntry,0,3);

    PopUpWindow::populate(addButton,0,4);
}

void PopUpWindowWrite::onAddClicked() {
    this->event->eventPassArg(std::string(nameEntry->get_text()), std::string(linkEntry->get_text()),windowAction);
    this->close();
}
