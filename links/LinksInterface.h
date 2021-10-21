#ifndef UNTITLED2_LINKSINTERFACE_H
#define UNTITLED2_LINKSINTERFACE_H
#include <vector>
struct Stations{
    std::string StationName;
    std::string StationLink;
    Stations(char* Name, char* Link):StationName(Name), StationLink(Link){};
};

class LinksInterface {
public:
    virtual void printStations()=0;
    virtual const std::string& getCurrentName()=0;
    virtual const std::string& getCurrentLink()=0;
    virtual void setNextStation()=0;
    virtual void setPreviousStation()=0;
    virtual void throwError(const std::string& error)=0;
    virtual const std::vector<Stations>& getAllStations() = 0;
};


#endif //UNTITLED2_LINKSINTERFACE_H
