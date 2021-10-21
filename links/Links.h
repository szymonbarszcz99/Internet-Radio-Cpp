#ifndef UNTITLED2_LINKS_H
#define UNTITLED2_LINKS_H
#include <string>
#include <fstream>
#include <iostream>
#include "LinksInterface.h"

class Links : public LinksInterface{

    std::vector<Stations> StationsVector;
    std::vector<Stations>::iterator StationsIterator;

public:
    Links();
    void printStations() override;
    const std::string& getCurrentName() override;
    const std::string& getCurrentLink() override;
    void setNextStation() override;
    void setPreviousStation() override;
    void throwError(const std::string& error) override;
    const std::vector<Stations>& getAllStations() override;
};


#endif //UNTITLED2_LINKS_H
