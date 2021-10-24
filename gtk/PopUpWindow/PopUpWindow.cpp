#include "PopUpWindow.h"


void PopUpWindow::populate(Gtk::Widget* widget, int left, int top, int width) {
    widget->set_margin_bottom(10);
    widget->set_margin_top(10);
    widget->set_margin_start(10);
    widget->set_margin_end(10);
    this->grid->attach(*widget, left,top, width);
}
