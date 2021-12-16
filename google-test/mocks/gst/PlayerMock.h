#ifndef UNTITLED2_PLAYERMOCK_H
#define UNTITLED2_PLAYERMOCK_H
#pragma once
#include <gmock/gmock.h>
#include "../../../gst/PlayerInterface.h"

class PlayerMock : public PlayerInterface{
public:
    MOCK_METHOD(void,changeStation,(const std::string& newLink),(override));
    MOCK_METHOD(void,pause,(),(override));
    MOCK_METHOD(void,play,(),(override));
    MOCK_METHOD(void,setVolume,(double volume),(override));
};


#endif //UNTITLED2_PLAYERMOCK_H
