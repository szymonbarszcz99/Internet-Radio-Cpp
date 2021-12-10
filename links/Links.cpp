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

possibleErrors Links::modifyStation(std::string name, std::string link) {
    possibleErrors nameError = Validator::validate(name);
    possibleErrors linkError = Validator::validate(link);
    if(nameError == VALID && linkError == VALID) {
        this->StationsIterator->StationName = name;
        this->StationsIterator->StationLink = link;

        this->fileOperations.writeFromVector(this->StationsVector);
        printStations();
        return VALID;
    }
    else if(nameError != VALID)return nameError;
    else return linkError;
}

possibleErrors Links::appendStation(std::string name, std::string link) {
    possibleErrors nameError = Validator::validate(name);
    possibleErrors linkError = Validator::validate(link);
    if(nameError == VALID && linkError == VALID){
        Stations newOne(name,link);
        this->StationsVector.push_back(newOne);
        this->StationsIterator = StationsVector.begin();

        this->fileOperations.writeFromVector(this->StationsVector);

        printStations();

        return VALID;
    }
    else if(nameError != VALID)return nameError;
    else return linkError;
}

const std::vector<std::pair<int, std::string>> &Links::getErrorVector() {
    return this->errorVector;
}

void Links::deleteStation() {
    StationsIterator = this->StationsVector.erase(StationsIterator);
    this->fileOperations.writeFromVector(this->StationsVector);
    printStations();
}

const Stations Links::getCurrentStation() {
    if(!this->StationsVector.empty()){
        return *this->StationsIterator;
    }
    else return Stations("","");
}
