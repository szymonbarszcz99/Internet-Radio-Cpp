#include "Links.h"

Links::Links() {
    this->stations.open("../stations.csv",std::fstream::in);
    if(!stations.is_open()){
        std::cout<<"Unable to open file!\nTrying to create it";
        this->stations.open("../stations.csv,std::fstream::app");
    }
    int i = 1;
    std::string tempName;
    std::string tempLink;
    while(stations.good()){
        getline(this->stations,tempName,',');
        if(stations.eof())break;
        getline(this->stations,tempLink, '\n');
        if(tempName.empty()){
            this->errorVector.emplace_back(std::make_pair(i,"No name"));
            continue;
        }
        else if(tempLink.empty()){
            this->errorVector.emplace_back(std::make_pair(i,"No link"));
            continue;
        }
        if(tempName[0] == '\n')tempName.erase(0,1);
        if(tempName.back() == '\n')tempName.erase(tempName.end()-1);
        Stations stations1(tempName,tempLink);
        this->StationsVector.push_back(stations1);
        i++;
    }
    if(i > 1)this->StationsIterator = StationsVector.begin();

    stations.close();

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

    printStations();
}

void Links::appendStation(std::string name, std::string link) {
    long currentIndex = std::distance(this->StationsVector.begin(), this->StationsIterator);

    this->stations.open("../stations.csv",std::fstream::app);
    if(!this->StationsVector.empty())this->stations<<std::endl;
    this->stations<<name<<","<<link;
    this->stations.close();

    Stations newOne(name,link);
    this->StationsVector.push_back(newOne);

    this->StationsIterator = this->StationsVector.begin() + currentIndex;

    printStations();
}

const std::vector<std::pair<int, std::string>> &Links::getErrorVector() {
    return this->errorVector;
}
