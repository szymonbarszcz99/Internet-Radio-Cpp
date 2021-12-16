#ifndef UNTITLED2_LINKSMOCK_H
#define UNTITLED2_LINKSMOCK_H
#pragma once
#include <gmock/gmock.h>
#include "../../../links/LinksInterface.h"

class LinksMock : public LinksInterface{
public:
    MOCK_METHOD(void,printStations,(),(override));
    MOCK_METHOD(const Stations,getCurrentStation,(),(override));
    MOCK_METHOD(void,setNextStation,(),(override));
    MOCK_METHOD(void,setPreviousStation,(),(override));
    MOCK_METHOD(const std::vector<Stations>&,getAllStations,(),(override));
    MOCK_METHOD(possibleErrors,appendStation,(std::string name, std::string link),(override));
    MOCK_METHOD(void,deleteStation,(),(override));
    MOCK_METHOD(possibleErrors,modifyStation,(std::string name, std::string link),(override));
    MOCK_METHOD((const std::vector<std::pair<int,std::string>>&),getErrorVector,(),(override));
};


#endif //UNTITLED2_LINKSMOCK_H
