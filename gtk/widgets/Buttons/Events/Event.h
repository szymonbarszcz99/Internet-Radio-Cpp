#ifndef UNTITLED2_EVENT_H
#define UNTITLED2_EVENT_H

class Event{
public:
    virtual ~Event(){};
    virtual void Clicked()=0;
};

#endif //UNTITLED2_EVENT_H
