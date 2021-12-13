#include "../../mocks/gtk/AppWindowMock.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
using namespace ::testing;

TEST(AppWindowTest, updateLabelTest){
    auto appWindowMock = std::make_shared<AppWindowMock>();
    ClickedStrategy::appWindowInterface = appWindowMock;
    EXPECT_CALL(*appWindowMock,updateSongNameLabel).Times(AtLeast(1));
    EventHandler eventHandler;
    PlayerEvent event(eventHandler);
    std::string song = "Toto - Africa";
    event.playerEventPassArg(song);
}