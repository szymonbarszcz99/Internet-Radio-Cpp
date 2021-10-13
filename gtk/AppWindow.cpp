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

void AppWindow::changeTextInLabel(const std::string& newText){
    this->grid->changeText(newText);
}