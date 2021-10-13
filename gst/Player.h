#ifndef UNTITLED2_PLAYER_H
#define UNTITLED2_PLAYER_H
extern "C"{
#include <gst/gst.h>
};
#include "iostream"

class Player {
    GstElement* pipeline;
    GError* error;
public:
    Player();
};


#endif //UNTITLED2_PLAYER_H
