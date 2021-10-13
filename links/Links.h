#ifndef UNTITLED2_LINKS_H
#define UNTITLED2_LINKS_H
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

struct Stations{
    std::string StationName;
    std::string StationLink;
    Stations(char* Name, char* Link);
};

class Links {
    std::vector<Stations> StationsVector;
public:
    Links();
    void printStations();
};


#endif //UNTITLED2_LINKS_H
