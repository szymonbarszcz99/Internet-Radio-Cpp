#ifndef UNTITLED2_PLAYER_H
#define UNTITLED2_PLAYER_H
extern "C"{
#include <gst/gst.h>
}
#include <iostream>
#include "PlayerInterface.h"

class Player : public PlayerInterface{
    GstElement* pipeline = nullptr;
    GError* error = nullptr;
public:
    Player(const std::string& link);
    void changeStation(const std::string& newLink);
    void pause();
    void play();
    void setVolume(double volume) override;
    ~Player(){
        delete this->pipeline;
        delete this->error;
    }
};


#endif //UNTITLED2_PLAYER_H
