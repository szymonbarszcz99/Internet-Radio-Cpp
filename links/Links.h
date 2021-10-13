#ifndef UNTITLED2_LINKS_H
#define UNTITLED2_LINKS_H
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "LinksInterface.h"

class Links : LinksInterface{
    struct Stations{
        std::string StationName;
        std::string StationLink;
        Stations(char* Name, char* Link);
    };
    std::vector<Stations> StationsVector;
    std::vector<Stations>::iterator StationsIterator;

public:
    Links();
    void printStations();
    const std::string& getCurrentName();
    const std::string& getCurrentLink();
    void setNextStation();
    void throwError(const std::string& error);
};


#endif //UNTITLED2_LINKS_H
