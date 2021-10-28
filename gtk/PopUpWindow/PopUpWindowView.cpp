#include "PopUpWindowView.h"

void PopUpWindowView::populate(std::string name, std::string link) {
    Gtk::Label* newLabelName = new Gtk::Label(name);
    Gtk::Label* newLabelLink = new Gtk::Label(link);

    this->PopUpWindow::populate(newLabelName,0,top);
    this->PopUpWindow::populate(newLabelLink,1,top);

    this->top++;

}
