#ifndef UNTITLED2_EVENT_H
#define UNTITLED2_EVENT_H
enum Actions{
    PLAY,
    PAUSE,
    NEXT,
    PREVIOUS,
    LABEL
};

class Event{
public:
    virtual ~Event(){};
    virtual void Clicked(Actions action)=0;
};

#endif //UNTITLED2_EVENT_H
