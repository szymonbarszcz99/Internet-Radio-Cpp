#include "Links.h"

Links::Links() {
    fileOperations.readToVector(this->StationsVector,this->errorVector);
    this->StationsIterator = this->StationsVector.begin();
    printStations();
}

void Links::printStations() {

    for(auto& it: this->StationsVector){
        std::cout<<it.StationName<<" "<<it.StationLink<<std::endl;
    }
    std::cout<<"Vector size: "<<StationsVector.size()<<std::endl;
}

std::string Links::getCurrentName() {
    if(!StationsVector.empty())return this->StationsIterator->StationName;
    else return "";
}

std::string Links::getCurrentLink() {;
    if(!StationsVector.empty())return this->StationsIterator->StationLink;
    else return "";
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

const std::vector<Stations> &Links::getAllStations() {
    return this->StationsVector;
}

void Links::updateCurrent(FileLine cmd,std::string name, std::string link) {
    if(cmd == MODIFY){
        this->StationsIterator->StationName = name;
        this->StationsIterator->StationLink = link;
    }
    else{
        StationsIterator = this->StationsVector.erase(StationsIterator);
    }

    this->fileOperations.writeFromVector(this->StationsVector);
    printStations();
}

void Links::appendStation(std::string name, std::string link) {

    Stations newOne(name,link);
    this->StationsVector.push_back(newOne);
    this->StationsIterator = StationsVector.begin();

    this->fileOperations.writeFromVector(this->StationsVector);

    printStations();
}

const std::vector<std::pair<int, std::string>> &Links::getErrorVector() {
    return this->errorVector;
}
