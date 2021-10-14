#include "Links.h"

Links::Stations::Stations(char *Name, char *Link) :StationName(Name),StationLink(Link){}

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
    this->StationsIterator = StationsVector.begin();

    stations.close();

    printStations();
}

void Links::printStations() {

    for(auto& it: this->StationsVector){
        std::cout<<it.StationName<<" "<<it.StationLink<<std::endl;
    }
    std::cout<<"Vector size: "<<StationsVector.size()<<std::endl;
}

const std::string& Links::getCurrentName() {
    return this->StationsIterator->StationName;
}

const std::string& Links::getCurrentLink() {
    return this->StationsIterator->StationLink;
}

void Links::setNextStation(){
    this->StationsIterator++;
}

void Links::throwError(const std::string &error) {
    std::cout<<error<<std::endl;
}