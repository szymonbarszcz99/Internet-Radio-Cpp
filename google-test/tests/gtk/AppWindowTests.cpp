#include "../../mocks/gtk/AppWindowMock.h"
#include "../../mocks/gst/PlayerMock.h"
#include "../../mocks/links/LinksMock.h"
#include <gtest/gtest.h>
using namespace ::testing;

class AppWindowTestFixture : public Test{
protected:
    EventHandler eventHandler;
    Event event{eventHandler};
    PlayerEvent playerEvent{eventHandler};
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

TEST_F(AppWindowTestFixture,updateLabelTest){
    EXPECT_CALL(*appWindowMock,updateLabel).Times(2);
    EXPECT_CALL(*linksMock,getCurrentStation).WillRepeatedly(Return (Stations("Nowy Swiat","nowy_swiat_url")));
    this->event.eventPassArg(NEXT);
    this->event.eventPassArg(PREVIOUS);
}

TEST_F(AppWindowTestFixture,updateLabelSongNameTest){
    EXPECT_CALL(*appWindowMock,updateSongNameLabel);
    std::string songName("Toto - Africa");
    playerEvent.playerEventPassArg(songName);
}

TEST_F(AppWindowTestFixture,createPopUpWindowViewTest){
    std::vector<Stations> returnVec{Stations("Nowy Swiat","nowy_swiat_url")};
    EXPECT_CALL(*appWindowMock,createPopUpWindowView);
    EXPECT_CALL(*linksMock,getAllStations).WillOnce(ReturnRef(returnVec));
    this->event.eventPassArg(VIEW_ALL);
}

TEST_F(AppWindowTestFixture,createPopUpWindowWriteTest){
    EXPECT_CALL(*appWindowMock,createPopUpWindowWrite).Times(2);
    EXPECT_CALL(*linksMock,getCurrentStation).WillOnce(Return(Stations("Nowy Swiat","nowy_swiat_url")));
    this->event.eventPassArg(ADD_STATION);
    this->event.eventPassArg(MODIFY_STATION);
}

TEST_F(AppWindowTestFixture,throwModalTest){
    const std::vector<std::pair<int,std::string>> errorVector{std::make_pair(1,"NON_ASCII"),std::make_pair(2,"EMPTY")};
    EXPECT_CALL(*appWindowMock,throwModal).Times(2);
    EXPECT_CALL(*linksMock,getErrorVector).WillOnce(ReturnRef(errorVector));
    EXPECT_CALL(*linksMock,getCurrentStation).WillOnce(Return(Stations("nowy","swiat")));
    this->event.onStartup();
}