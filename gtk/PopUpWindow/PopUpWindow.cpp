#include "PopUpWindow.h"

void PopUpWindow::populate(Gtk::Widget* widget, int left, int top, int width) {
    this->widgetVec.push_back(std::make_unique<Gtk::Widget>(std::move(*widget)));
    widgetVec.back()->property_margin() = 10;
    this->grid->attach(*widgetVec.back(), left, top, width);
    delete widget;
}
