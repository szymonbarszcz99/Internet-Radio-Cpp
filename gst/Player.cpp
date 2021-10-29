#include "Player.h"

Player::Player(const std::string& link){
    gst_init(nullptr, nullptr);
    GstStateChangeReturn ret;
    if(!link.empty()){
        std::cout<<"Player constructor"<<std::endl;
        std::string uri("playbin uri=");
        uri.append(link);

        this->pipeline = gst_parse_launch(uri.c_str(),&this->error);

        if(!this->pipeline){
            std::cout<<"Pipeline creation error\n";
            g_print("%s\n",error->message);
        }
        ret = gst_element_set_state(this->pipeline, GST_STATE_PLAYING);
        if(ret == 0){
            printf("State change failed\n");
        }
    }
}

void Player::changeStation(const std::string& newLink) {
    gst_element_set_state(this->pipeline,GST_STATE_READY);

    std::cout<<newLink<<std::endl;
    g_object_set(this->pipeline,"uri",newLink.c_str(),NULL);

    gst_element_set_state(this->pipeline,GST_STATE_PLAYING);
}

void Player::pause() {
    gst_element_set_state(this->pipeline,GST_STATE_PAUSED);
}

void Player::play(){
    gst_element_set_state(this->pipeline,GST_STATE_PLAYING);
}

void Player::setVolume(double volume) {
    if(this->pipeline != nullptr)g_object_set(this->pipeline,"volume",volume/100,NULL);
}
