#ifndef UNTITLED2_PLAYER_H
#define UNTITLED2_PLAYER_H
extern "C"{
#include <gst/gst.h>
}
#include <iostream>
#include "PlayerInterface.h"
#include "PlayerEvent.h"

class Player : public PlayerInterface{
    GstElement* pipeline = nullptr;
    GError* error = nullptr;
    std::unique_ptr<PlayerEvent> playerEvent;
public:
    Player(const std::string& link,std::unique_ptr<PlayerEvent> playerEvent);
    void changeStation(const std::string& newLink) override;
    void pause() override;
    void play() override;
    void setVolume(double volume) override;
    ~Player() override{
        std::cout<<"Player destructor"<<std::endl;
        if(this->pipeline != nullptr) {
            gst_element_set_state(this->pipeline,GST_STATE_NULL);
            gst_object_unref(this->pipeline);
        }
        if(this->error != nullptr)g_error_free(this->error);
        //gst_deinit();
    }
};


#endif //UNTITLED2_PLAYER_H
