#include "WidgetGrid.h"

WidgetGrid::WidgetGrid():Gtk::Grid() {
    auto stationName = new StationName();
    attach(*stationName,0,0,4);

    int left = 0;
    auto buttonsAll = new ButtonsAll();
    for(auto it: buttonsAll->getVector()){
        attach(*it,left++,1,1,1);
    }
}
void WidgetGrid::changeText(const std::string& newText){
    auto label = dynamic_cast<Gtk::Label *>(this->get_child_at(0, 0));
    label->set_text(newText);
}