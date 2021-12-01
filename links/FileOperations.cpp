#include <iostream>
#include "FileOperations.h"

void FileOperations::readToVector(std::vector<Stations> &StationsVector,
                                  std::vector<std::pair<int,std::string>>& errorVector) {
    int i = 1; //Numer linijki dla komunikatów o błędach

    //Najpierw zakładamy, że plik istnieje i próbujemy go otworzyć
    this->stations.open("stations.csv",std::fstream::in);

    if(!stations.is_open()){
        //Jeżeli się nie otworzył, to w katalogu z radiem go nie ma i trzeba go stworzyć
        std::cout<<"Unable to open file!\nTrying to create it";
        this->stations.open("stations.csv,std::fstream::app");
    }
    else{
        //Jeżeli plik się znalazł to jest sens go czytać
        //          FUNKCJA DO CZYTANIA PLIKU:
        std::string tempName;
        std::string tempLink;
        //Iterujemy linijka po linijce dopóki da się czytać plik
        while(!stations.eof()){
            //Czytamy pola CSV
            getline(this->stations,tempName,',');
            //Jeżeli przed EOF pojawił się enter to koniec pliku pokaże się teraz
            if(stations.eof()){
                break;
            }
            getline(this->stations,tempLink, '\n');

            possibleErrors name
            else{

            }
            i++;
        }
        stations.close();
    }
}

void FileOperations::writeFromVector(std::vector<Stations> &StationsVector) {
    //Stwórz nowy plik
    std::fstream newFile("stations_temp.csv",std::fstream::app);
    this->stations.open("stations.csv");

    if(!newFile.is_open() || !this->stations.is_open()){
        std::cout<<"Unable to open files"<<std::endl;
    }

    //Zapisz wektor
    for(const auto& it: StationsVector){
        newFile<<it.StationName<<","<<it.StationLink<<std::endl;
    }
    this->stations.close();
    newFile.close();

    //Zamień pliki
    remove("stations.csv");
    rename("stations_temp.csv", "../stations.csv");
}
