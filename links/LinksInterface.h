#ifndef UNTITLED2_LINKSINTERFACE_H
#define UNTITLED2_LINKSINTERFACE_H


class LinksInterface {
    virtual void printStations()=0;
    virtual const std::string& getCurrentName()=0;
    virtual const std::string& getCurrentLink()=0;
    virtual void setNextStation()=0;
    virtual void throwError(const std::string& error)=0;
};


#endif //UNTITLED2_LINKSINTERFACE_H
