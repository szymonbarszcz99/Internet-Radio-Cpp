#include "../../mocks/gtk/AppWindowMock.h"
#include "../../mocks/gst/PlayerMock.h"
#include "../../mocks/links/LinksMock.h"
using namespace ::testing;

class linksTestFixture : public Test{
protected:
    EventHandler eventHandler;
    Event event{eventHandler};
    std::shared_ptr<AppWindowMock> appWindowMock;
    std::shared_ptr<LinksMock> linksMock;
    std::shared_ptr<PlayerMock> playerMock;
    void SetUp() override{
        appWindowMock = std::make_shared<AppWindowMock>();
        linksMock = std::make_shared<LinksMock>();
        playerMock = std::make_shared<PlayerMock>();
        ClickedStrategy::appWindowInterface = appWindowMock;
        ClickedStrategy::linksInterface = linksMock;
        ClickedStrategy::playerInterface = playerMock;
    }
};

TEST_F(linksTestFixture,appendTest){
    EXPECT_CALL(*linksMock,appendStation).Times(3);
    std::string stationName = "Nowy Świat";
    std::string stationURL = "nowyswiat.pl";
    this->event.eventPassArg(stationName,stationURL,ADD_STATION);
    stationName = "Nowy,,,,,,,,Swiat";
    this->event.eventPassArg(stationName, stationURL,ADD_STATION);
    stationName.clear();
    this->event.eventPassArg(stationName,stationURL,ADD_STATION);
}

TEST_F(linksTestFixture,getCurrentNameTest){
    EXPECT_CALL(*linksMock,getCurrentStation).WillRepeatedly(Return(Stations{"Nowy Swiat","nowyswiat.pl"}));
    EXPECT_CALL(*linksMock,setNextStation);
    EXPECT_CALL(*linksMock,setPreviousStation);
    this->event.eventPassArg(NEXT);
    this->event.eventPassArg(PREVIOUS);
}

TEST_F(linksTestFixture,getAllStationsTest){
    std::vector<Stations> returnVec{Stations("Nowy Swiat","nowy_swiat_url")};
    EXPECT_CALL(*linksMock,getAllStations).WillRepeatedly(ReturnRef(returnVec));
    this->event.eventPassArg(VIEW_ALL);
}

TEST_F(linksTestFixture,deleteTest){
    EXPECT_CALL(*linksMock,deleteStation);
    EXPECT_CALL(*linksMock,getCurrentStation).WillOnce(Return(Stations("Nowy Swiat","nowyswiat.pl")));
    this->event.eventPassArg(DELETE_STATION);
}

TEST_F(linksTestFixture,modifyTest){
    EXPECT_CALL(*linksMock,modifyStation);
    std::string stationName = "Nowy Świat";
    std::string stationURL = "nowyswiat.pl";
    this->event.eventPassArg(stationName,stationURL,MODIFY_STATION);
}

TEST_F(linksTestFixture,getErroVectorTest){
    const std::vector<std::pair<int,std::string>> errorVector{std::make_pair(1,"NON_ASCII"),std::make_pair(2,"EMPTY")};
    EXPECT_CALL(*linksMock,getErrorVector).WillOnce(ReturnRef(errorVector));
    EXPECT_CALL(*linksMock,getCurrentStation).WillOnce(Return(Stations("","")));
    this->event.onStartup();
}

