#include "PopUpWindowView.h"

void PopUpWindowView::populate(const std::string& name, const std::string& link) {
    auto* newLabelName = new Gtk::Label(name);
    auto* newLabelLink = new Gtk::Label(link);

    this->PopUpWindow::populate(newLabelName,0,top);
    this->PopUpWindow::populate(newLabelLink,1,top);

    this->top++;
}
