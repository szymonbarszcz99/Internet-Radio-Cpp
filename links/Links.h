#ifndef UNTITLED2_LINKS_H
#define UNTITLED2_LINKS_H
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class Links {
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
};


#endif //UNTITLED2_LINKS_H
