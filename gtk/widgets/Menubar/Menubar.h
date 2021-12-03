#ifndef UNTITLED2_MENUBAR_H
#define UNTITLED2_MENUBAR_H
#include <gtkmm/menubar.h>
#include "FileMenuButton.h"
#include "HelpMenuButton.h"
#include "BluetoothMenuButton.h"

class Menubar : public Gtk::MenuBar{
    std::unique_ptr<FileMenuButton> fileMenuButton;
    std::unique_ptr<HelpMenuButton> helpMenuButton;
    std::unique_ptr<BluetoothMenuButton> bluetoothMenuButton;
public:
    explicit Menubar(const Event& event);
    ~Menubar() override{
        std::cout<<"Menubar destructor"<<std::endl;
    }
};


#endif //UNTITLED2_MENUBAR_H
