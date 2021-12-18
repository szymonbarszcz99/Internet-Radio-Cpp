#ifndef UNTITLED2_BLUETOOTH_H
#define UNTITLED2_BLUETOOTH_H
#include "BluetoothInterface.h"
#include <cstdio>

class Bluetooth : public BluetoothInterface{
public:
    void scan(std::map<std::string, std::string>& devices) override;
};


#endif //UNTITLED2_BLUETOOTH_H
