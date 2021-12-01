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
    //TODO(Make one getter)
    std::string getCurrentName() override;
    std::string getCurrentLink() override;
    void setNextStation() override;
    void setPreviousStation() override;
    const std::vector<Stations>& getAllStations() override;
    void updateCurrent(FileLine cmd,std::string name = "", std::string link = "") override;
    void appendStation(std::string name, std::string link) override;
    ~Links() override{
        std::cout<<"Links destructor"<<std::endl;
    }
    const std::vector<std::pair<int,std::string>>& getErrorVector();
};


#endif //UNTITLED2_LINKS_H
