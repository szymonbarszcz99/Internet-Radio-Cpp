#include "BtWindow.h"

void BtWindow::addList(std::map<std::string, std::string> devices) {
    int i = 0;
    for(auto it: devices){
        this->list.append(it.first);
        this->list.set_text(i,1,it.second);
        i++;
    }

    this->remove();
    this->add(this->list);

    this->property_deletable() = true;
    this->property_resizable() = true;
    this->show_all();
}
