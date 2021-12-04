#include <iostream>
#include "BtWindow.h"

void BtWindow::addList(std::map<std::string, std::string> devices) {
    int i = 0;
    for(auto it: devices){
        this->list.append(it.first);
        this->list.set_text(i,1,it.second);
        i++;
    }
    this->list.signal_row_activated().connect(sigc::mem_fun(*this,&BtWindow::on_my_row_activated));

    this->remove();
    this->add(this->list);

    this->property_deletable() = true;
    this->property_resizable() = true;
    this->show_all();
}

void BtWindow::on_my_row_activated(const Gtk::TreeModel::Path& path, Gtk::TreeViewColumn* column) {
    auto selection = this->list.get_text(this->list.get_selected()[0],1);
    std::cout<<"Addr: "<<selection<<std::endl;
}
