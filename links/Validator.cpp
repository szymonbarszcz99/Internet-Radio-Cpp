#include "Validator.h"

bool Validator::checkCommas(const std::string &stringToAnalyze) {
        std::size_t commaPos = stringToAnalyze.find(',');
        if(commaPos == std::string::npos){
            std::cout<<"No comma found"<<std::endl;
            return true;
        }
        else return false;

}

void Validator::clearWhitespaces(std::string &stringToAnalyze) {
    while(std::isspace(stringToAnalyze[0]) || stringToAnalyze[0] == '\n')
        stringToAnalyze.erase(0,1);
    while(std::isspace(stringToAnalyze.back()) || stringToAnalyze.back() == '\n')
        stringToAnalyze.erase(stringToAnalyze.end() - 1);

    std::cout<<"String after removing whitespaces: "<<stringToAnalyze<<std::endl;
}


bool Validator::checkContent(const std::string &stringToAnalyze) {
    return !stringToAnalyze.empty();
}

possibleErrors Validator::validate(std::string &stringToAnalyze) {
    if(!checkCommas(stringToAnalyze)) return COMMA;
    else if(!checkContent(stringToAnalyze)) return EMPTY;
    else{
        clearWhitespaces(stringToAnalyze);
        return VALID;
    }
}
