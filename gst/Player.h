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
        std::cout<<"Player destructor"<<std::endl;
        gst_object_unref(this->pipeline);
        if(this->error != nullptr)g_error_free(this->error);
        //gst_deinit();
    }
};


#endif //UNTITLED2_PLAYER_H
