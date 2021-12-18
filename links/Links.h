#ifndef UNTITLED2_LINKS_H
#define UNTITLED2_LINKS_H
#include <string>
#include <fstream>
#include <iostream>
#include "FileOperations.h"

class Links : public LinksInterface{
    FileOperations fileOperations;
    std::fstream stations;
    std::vector<Stations> StationsVector;
    std::vector<Stations>::iterator StationsIterator;
    std::vector<std::pair<int,std::string>> errorVector;

public:
    Links();
    void printStations() override;
    Stations getCurrentStation() override;
    void setNextStation() override;
    void setPreviousStation() override;
    const std::vector<Stations>& getAllStations() override;
    possibleErrors appendStation(std::string name, std::string link) override;
    void deleteStation() override;
    possibleErrors modifyStation(std::string name, std::string link) override;
    ~Links() override{
        std::cout<<"Links destructor"<<std::endl;
    }
    const std::vector<std::pair<int,std::string>>& getErrorVector() override;
};


#endif //UNTITLED2_LINKS_H
