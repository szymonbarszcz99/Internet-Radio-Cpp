#ifndef UNTITLED2_BLUETOOTH_H
#define UNTITLED2_BLUETOOTH_H
#include "BluetoothInterface.h"
#include <cstdio>

class Bluetooth : public BluetoothInterface{
public:
    std::map<std::string, std::string> scan() override;
    void connectToDevice(std::string addr) override;

};


#endif //UNTITLED2_BLUETOOTH_H
