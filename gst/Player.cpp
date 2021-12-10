#include "Player.h"

static gboolean bus_callback(GstBus * bus, GstMessage * message, gpointer data)
{
    PlayerEvent* playerEvent = static_cast<PlayerEvent*>(data);
    if(GST_MESSAGE_TYPE(message) == GST_MESSAGE_TAG){
        GstTagList* tags = nullptr;
        gst_message_parse_tag (message, &tags);
        printf("%s\n",gst_tag_list_to_string(tags));
        gchar* value;
        if(gst_tag_list_get_string(tags,"title",&value)){
            playerEvent->playerEventPassArg(std::string(value));
        }
        gst_tag_list_unref (tags);
    }
    return true;
}

Player::Player(const std::string& link, std::unique_ptr<PlayerEvent> playerEvent){
    std::cout<<"Player constructor"<<std::endl;

    this->playerEvent = std::move(playerEvent);

    gst_init(nullptr, nullptr);
    GstStateChangeReturn ret;
    GstBus* bus;
    std::string uri("playbin uri=");

    if(!link.empty()) {
        uri.append(link);
        this->pipeline = gst_parse_launch(uri.c_str(), &this->error);
    }
    else{
        this->pipeline = gst_parse_launch(uri.c_str(), &this->error);
    }

    if(!this->pipeline){
            std::cout<<"Pipeline creation error\n";
            g_print("%s\n",error->message);
    }
    else{
        std::cout<<"Pipeline created!"<<std::endl;
        bus = gst_pipeline_get_bus (GST_PIPELINE (pipeline));
        gst_bus_add_watch (bus, bus_callback,this->playerEvent.get());
    }

    if(!link.empty()){
        ret = gst_element_set_state(this->pipeline, GST_STATE_PLAYING);
        if(ret == 0) {
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
