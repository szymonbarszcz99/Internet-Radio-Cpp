#ifndef UNTITLED2_BLUETOOTHINTERFACE_H
#define UNTITLED2_BLUETOOTHINTERFACE_H
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>
#include <iostream>
#include <unistd.h>

class BluetoothInterface {
public:
    virtual std::map<std::string, std::string> scan() = 0;
    virtual void connectToDevice(std::string addr) = 0;
};


#endif //UNTITLED2_BLUETOOTHINTERFACE_H
