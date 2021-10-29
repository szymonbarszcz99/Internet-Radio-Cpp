#ifndef UNTITLED2_LINKSINTERFACE_H
#define UNTITLED2_LINKSINTERFACE_H
#include <vector>

enum FileLine{
    MODIFY,
    DELETE
};

struct Stations{
    std::string StationName;
    std::string StationLink;
    //Stations(char* Name, char* Link):StationName(Name), StationLink(Link){};
    Stations(std::string Name,std::string Link): StationName(Name),StationLink(Link){};
};

class LinksInterface {
public:
    virtual void printStations()=0;
    virtual const std::string& getCurrentName()=0;
    virtual const std::string& getCurrentLink()=0;
    virtual void setNextStation()=0;
    virtual void setPreviousStation()=0;
    virtual const std::vector<Stations>& getAllStations() = 0;
    virtual void updateCurrent(FileLine cmd,std::string name = "", std::string link = "")=0;
    virtual void appendStation(std::string name, std::string link)=0;
    virtual ~LinksInterface(){}
};


#endif //UNTITLED2_LINKSINTERFACE_H
