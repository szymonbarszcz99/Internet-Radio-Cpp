#ifndef UNTITLED2_FILEOPERATIONS_H
#define UNTITLED2_FILEOPERATIONS_H
#include <fstream>
#include "LinksInterface.h"
#include "Validator.h"

class FileOperations {
    std::fstream stations;
public:
    void writeFromVector(std::vector<Stations>& StationsVector);
    void readToVector(std::vector<Stations>& StationsVector,
                      std::vector<std::pair<int,std::string>>& errorVector);
};


#endif //UNTITLED2_FILEOPERATIONS_H
