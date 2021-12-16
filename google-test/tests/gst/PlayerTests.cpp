#include "../../mocks/gtk/AppWindowMock.h"
#include "../../mocks/gst/PlayerMock.h"
#include "../../mocks/links/LinksMock.h"
#include <gtest/gtest.h>
using namespace ::testing;

class PlayerTestFixture : public Test{
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

TEST_F(PlayerTestFixture,playTest){
    EXPECT_CALL(*playerMock,play);
    event.eventPassArg(PLAY);

}

TEST_F(PlayerTestFixture, pauseTest){
    EXPECT_CALL(*playerMock,pause);
    event.eventPassArg(PAUSE);
}

TEST_F(PlayerTestFixture, changeTest){
    EXPECT_CALL(*playerMock,changeStation).Times(2);
    EXPECT_CALL(*linksMock,getCurrentStation).Times(2).WillRepeatedly(Return(Stations("nowy","swiat")));
    event.eventPassArg(NEXT);
    event.eventPassArg(PREVIOUS);
}

TEST_F(PlayerTestFixture,changeVolumeTest){
    EXPECT_CALL(*playerMock,setVolume).Times(3);
    event.eventPassArg((double)0);
    event.eventPassArg((double)50);
    event.eventPassArg((double)100);
}