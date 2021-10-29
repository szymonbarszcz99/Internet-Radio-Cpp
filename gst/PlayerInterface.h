#ifndef UNTITLED2_PLAYERINTERFACE_H
#define UNTITLED2_PLAYERINTERFACE_H
#include <memory>

class PlayerInterface{
public:
    virtual void changeStation(const std::string& newLink)=0;
    virtual void pause()=0;
    virtual void play()=0;
    virtual void setVolume(double volume)=0;
    virtual ~PlayerInterface(){};
};

#endif //UNTITLED2_PLAYERINTERFACE_H
