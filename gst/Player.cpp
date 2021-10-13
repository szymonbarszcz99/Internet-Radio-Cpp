#include "Player.h"

Player::Player():pipeline(nullptr),error(nullptr){
    gst_init(nullptr, nullptr);
    GstStateChangeReturn ret;

    this->pipeline = gst_parse_launch("playbin uri=https://n08a-eu.rcs.revma.com/ypqt40u0x1zuv?rj-ttl=5&rj-tok=AAABeZK5G1oAJcrQH3ZWEgE4hQ",&this->error);

    if(!this->pipeline){
        std::cout<<"Pipeline creation error\n";
        g_print("%s\n",error->message);
    }

    ret = gst_element_set_state(this->pipeline, GST_STATE_PLAYING);
    if(ret == 0){
        printf("State change failed\n");
    }
}