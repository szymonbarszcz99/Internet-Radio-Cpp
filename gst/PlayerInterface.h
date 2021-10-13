#ifndef UNTITLED2_PLAYERINTERFACE_H
#define UNTITLED2_PLAYERINTERFACE_H

class PlayerInterface{
    virtual void changeStation(const std::string& newLink)=0;
    virtual void pause()=0;
    virtual void play()=0;
};

#endif //UNTITLED2_PLAYERINTERFACE_H
