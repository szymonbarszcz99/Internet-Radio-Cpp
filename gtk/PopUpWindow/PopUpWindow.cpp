#include "PopUpWindow.h"

void PopUpWindow::populate(Gtk::Widget *widget, int left, int top, int width) {
    widget->property_margin() = 10;
    this->grid->attach(*widget, left, top, width);
}
