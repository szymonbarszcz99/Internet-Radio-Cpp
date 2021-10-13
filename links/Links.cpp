#include "Links.h"

Stations::Stations(char *Name, char *Link) :StationName(Name),StationLink(Link){}

Links::Links() {
    std::ifstream stations("../stations.csv");
    if(!stations.is_open()){
        std::cout<<"Unable to open file!\n";
    }

    char* tempName = (char *)malloc(sizeof(char) * 512);
    char* tempLink = (char *)malloc(sizeof(char) * 512);
    while(stations.good()){
        stations.getline(tempName,512,',');
        if(stations.eof())break;
        stations.getline(tempLink, 512);
        Stations stations1(tempName,tempLink);
        this->StationsVector.push_back(stations1);
    }

    stations.close();

    printStations();
}

void Links::printStations() {

    for(auto& it: this->StationsVector){
        std::cout<<it.StationName<<" "<<it.StationLink<<std::endl;
    }
    std::cout<<"Vector size: "<<StationsVector.size()<<std::endl;
}