#include "AppWindow.h"

AppWindow::AppWindow():Gtk::ApplicationWindow() {
    set_title("Internet Radio");
    attachGrid();
}

void AppWindow::attachGrid(){
    this->grid = new WidgetGrid();
    add(*(this->grid));
    this->grid->show_all();
}

void AppWindow::updateLabel(const std::string &newStation) {
    this->grid->getStationName()->set_text(newStation);
}

WidgetGrid *AppWindow::getGrid() {
    return this->grid;
}

