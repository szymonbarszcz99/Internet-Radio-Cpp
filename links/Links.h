#ifndef UNTITLED2_LINKS_H
#define UNTITLED2_LINKS_H
#include <string>
#include <fstream>
#include <iostream>
#include "LinksInterface.h"

class Links : public LinksInterface{
    std::fstream stations;
    std::vector<Stations> StationsVector;
    std::vector<Stations>::iterator StationsIterator;

public:
    Links();
    void printStations() override;
    const std::string& getCurrentName() override;
    const std::string& getCurrentLink() override;
    void setNextStation() override;
    void setPreviousStation() override;
    const std::vector<Stations>& getAllStations() override;
    void updateCurrent(FileLine cmd,std::string name = "", std::string link = "") override;
    void appendStation(std::string name, std::string link) override;
    ~Links() override{
        std::cout<<"Links destructor"<<std::endl;
    }
};


#endif //UNTITLED2_LINKS_H
