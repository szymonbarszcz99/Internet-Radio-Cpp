#ifndef UNTITLED2_LINKSINTERFACE_H
#define UNTITLED2_LINKSINTERFACE_H
#include <utility>
#include <vector>
#include "Validator.h"

struct Stations{
    std::string StationName;
    std::string StationLink;
    Stations(std::string Name,std::string Link): StationName(std::move(Name)),StationLink(std::move(Link)){};
};

class LinksInterface {
public:
    virtual void printStations()=0;
    virtual Stations getCurrentStation() = 0;
    virtual void setNextStation()=0;
    virtual void setPreviousStation()=0;
    virtual const std::vector<Stations>& getAllStations() = 0;
    virtual possibleErrors appendStation(std::string name, std::string link)=0;
    virtual void deleteStation() = 0;
    virtual possibleErrors modifyStation(std::string name, std::string link) = 0;
    virtual ~LinksInterface()= default;
    virtual const std::vector<std::pair<int,std::string>>& getErrorVector() = 0;
};


#endif //UNTITLED2_LINKSINTERFACE_H
