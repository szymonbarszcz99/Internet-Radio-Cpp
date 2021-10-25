#include "Links.h"

Links::Links() {
    this->stations.open("../stations.csv");
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
    if(++this->StationsIterator == this->StationsVector.end()){
        this->StationsIterator = this->StationsVector.begin();
    }
}

void Links::setPreviousStation() {
    if(this->StationsIterator == this->StationsVector.begin()){
        this->StationsIterator = this->StationsVector.end()-1;
    }
    else{
        this->StationsIterator--;
    }
}

void Links::throwError(const std::string &error) {
    std::cout<<error<<std::endl;
}

const std::vector<Stations> &Links::getAllStations() {
    return this->StationsVector;
}

void Links::updateCurrent(std::string newName, std::string newLink) {
    //name = name + "," + link;
    std::string temp_line;
    long index = std::distance(this->StationsVector.begin(),this->StationsIterator);
    long i = 0;

    std::fstream newFile("../stations_temp.csv",std::fstream::out);
    this->stations.open("../stations.csv");

    if(!newFile.is_open() || !this->stations.is_open()){
        std::cout<<"Unable to open files"<<std::endl;
    }

    while(getline(this->stations, temp_line)){
        if(i == index){
            newFile<<newName<<","<<newLink<<std::endl;
        }
        else{
            newFile<<temp_line<<std::endl;
        }
        i++;
    }
    this->stations.close();
    newFile.close();

    this->StationsIterator->StationName = newName;
    this->StationsIterator->StationLink = newLink;

    remove("../stations.csv");
    rename("../stations_temp.csv", "../stations.csv");

    printStations();
}
