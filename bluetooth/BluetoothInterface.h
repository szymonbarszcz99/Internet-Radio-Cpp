#ifndef UNTITLED2_BLUETOOTHINTERFACE_H
#define UNTITLED2_BLUETOOTHINTERFACE_H
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>
#include <iostream>
#include <unistd.h>

class BluetoothInterface {
public:
    virtual void scan(std::map<std::string, std::string>& devices) = 0;
};


#endif //UNTITLED2_BLUETOOTHINTERFACE_H
