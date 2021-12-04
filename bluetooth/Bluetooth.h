#ifndef UNTITLED2_BLUETOOTH_H
#define UNTITLED2_BLUETOOTH_H
#include "BluetoothInterface.h"

class Bluetooth : public BluetoothInterface{
public:
    std::map<std::string, std::string> scan() override;

};


#endif //UNTITLED2_BLUETOOTH_H
