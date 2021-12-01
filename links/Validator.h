#ifndef UNTITLED2_VALIDATOR_H
#define UNTITLED2_VALIDATOR_H
#include <string>
#include <iostream>

enum possibleErrors {
    COMMA,
    NON_ASCII,
    EMPTY,
    VALID
};

class Validator {

private:
    static void clearWhitespaces(std::string& stringToAnalyze);
    static bool checkCommas(const std::string& stringToAnalyze);
    static bool checkASCII(const std::string& stringToAnalyze);
    static bool checkContent(const std::string& stringToAnalyze);
public:
    Validator(){
        std::cout<<"Validator constructor"<<std::endl;
    }
    static possibleErrors validate(std::string& stringToAnalyze);
    ~Validator(){
        std::cout<<"Validator destructor"<<std::endl;
    }
};



#endif //UNTITLED2_VALIDATOR_H
