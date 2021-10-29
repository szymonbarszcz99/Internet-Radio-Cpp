#include "Links.h"

Links::Links() {
    this->stations.open("../stations.csv",std::fstream::out);
    if(!stations.is_open()){
        std::cout<<"Unable to open file!\n";
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

    std::string temp_line;
    long index = std::distance(this->StationsVector.begin(),this->StationsIterator);
    long i = 0;
    unsigned long maxI = this->StationsVector.size()-1;

    std::fstream newFile("../stations_temp.csv",std::fstream::out);
    this->stations.open("../stations.csv");

    if(!newFile.is_open() || !this->stations.is_open()){
        std::cout<<"Unable to open files"<<std::endl;
    }
    if(cmd == DELETE){
        while(getline(this->stations, temp_line)){

            if(i == index){
                i++;
                continue;
            }
            else{
                if((i == 1 && index == 0) || i==0)newFile<<temp_line;
                else newFile<<std::endl<<temp_line;
                i++;
            }

        }
    }
    else{
        while(getline(this->stations, temp_line)){

            if(i == index){
                newFile<<name<<","<<link;
            }
            else{
                newFile<<temp_line;
            }
            if(i != maxI)newFile<<std::endl;
            i++;
        }
    }

    this->stations.close();
    newFile.close();

    if(cmd == MODIFY){
        this->StationsIterator->StationName = name;
        this->StationsIterator->StationLink = link;
    }
    else{
        StationsIterator = this->StationsVector.erase(StationsIterator);
    }


    remove("../stations.csv");
    rename("../stations_temp.csv", "../stations.csv");

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
