#include "BtWindow.h"

void BtWindow::addList() {
    int i = 0;
    for(auto it: devices){
        this->list.append(it.first);
        this->list.set_text(i,1,it.second);
        i++;
    }
    this->list.signal_row_activated().connect(sigc::mem_fun(*this,&BtWindow::on_my_row_activated));

    this->remove();
    this->box = Gtk::Box(Gtk::ORIENTATION_VERTICAL);
    this->box.pack_start(list);
    this->label.set_text("");
    this->box.pack_end(this->label);
    this->add(this->box);

    this->property_deletable() = true;
    this->property_resizable() = true;
    this->show_all();
}

void BtWindow::on_my_row_activated(const Gtk::TreeModel::Path& path, Gtk::TreeViewColumn* column) {
    auto selection = this->list.get_text(this->list.get_selected()[0],1);
    std::cout<<"Addr: "<<selection<<std::endl;

    char stdoutBuff[512];
    std::string outString;
    FILE* cmd = popen(("bluetoothctl connect " + selection).c_str(), "r");
    while(fgets(stdoutBuff,512,cmd)){
        outString += stdoutBuff;
    }
    if(outString.find("success") != std::string::npos){
        currentSpeaker = selection;
        this->close();
    }
    else{
        this->label.set_text("Unable to connect");
    }

    pclose(cmd);
    std::cout<<outString<<std::endl;
}

void BtWindow::disconnect() {
    if(!currentSpeaker.empty()) {
        char stdoutBuff[512];
        std::string outString;
        FILE *cmd = popen(("bluetoothctl disconnect " + currentSpeaker).c_str(), "r");
        while (fgets(stdoutBuff, 512, cmd)) {
            outString += stdoutBuff;
        }
        currentSpeaker = "";
        pclose(cmd);
    }
}

void BtWindow::stopScanning() {
    this->dispatcher.emit();
}
