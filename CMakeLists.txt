cmake_minimum_required(VERSION 3.16)
project(untitled2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(THREADS_PREFER_PTHREAD_FLAG ON)
add_subdirectory(google-test/lib/googletest-main)

find_package(PkgConfig)
find_package(Threads REQUIRED)
find_package(X11 REQUIRED)

pkg_check_modules(GSTREAMER REQUIRED gstreamer-1.0)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)
pkg_check_modules(BLUEZ REQUIRED bluez)
include_directories(
        ${GLIB_INCLUDE_DIRS}
        ${GSTREAMER_INCLUDE_DIRS}
        ${GTKMM_INCLUDE_DIRS}
        ${BLUEZ_INCLUDE_DIRS}
        ${X11_INCLUDE_DIR}
        ${gtest_SOURCE_DIR}/include
        ${gtest_SOURCE_DIR}
)

link_directories(
        ${GLIB_LIBRARY_DIRS}
        ${GSTREAMER_LIBRARY_DIRS}
        ${GTKMM_LIBRARY_DIRS}
        ${BLUEZ_LIBRARY_DIRS}
        ${X11_LIBRARIES}
)

add_executable(untitled2 main.cpp gtk/RadioApp.cpp gtk/RadioApp.h gtk/AppWindow.cpp gtk/AppWindow.h gst/Player.cpp gst/Player.h links/Links.cpp links/Links.h gst/PlayerInterface.h gtk/AppWindowInterface.h links/LinksInterface.h EventHandler.cpp EventHandler.h gtk/widgets/Events/Event.h gtk/widgets/AppButton/AppButton.cpp gtk/widgets/AppButton/AppButton.h gtk/widgets/AppSlider/AppSlider.cpp gtk/widgets/AppSlider/AppSlider.h gtk/widgets/Menubar/Menubar.cpp gtk/widgets/Menubar/Menubar.h gtk/widgets/Menubar/FileMenuButton.cpp gtk/widgets/Menubar/FileMenuButton.h gtk/widgets/Events/Event.cpp gtk/PopUpWindow/PopUpWindowView.cpp gtk/PopUpWindow/PopUpWindowView.h gtk/PopUpWindow/PopUpWindowWrite.cpp gtk/PopUpWindow/PopUpWindowWrite.h gtk/PopUpWindow/PopUpWindow.cpp gtk/PopUpWindow/PopUpWindow.h Strategy/ClickedStrategy.h Strategy/PlayerClickedStrategy.cpp Strategy/PlayerClickedStrategy.h gtk/widgets/Events/Enums.h Strategy/MenubarClickedStrategy.cpp Strategy/MenubarClickedStrategy.h Strategy/PopUpWindowStrategy.cpp Strategy/PopUpWindowStrategy.h Strategy/SliderStrategy.cpp Strategy/SliderStrategy.h Strategy/StartupStrategy.cpp Strategy/StartupStrategy.h Strategy/BusMessageStrategy.cpp Strategy/BusMessageStrategy.h gst/PlayerEvent.cpp gst/PlayerEvent.h links/FileOperations.cpp links/FileOperations.h links/Validator.cpp links/Validator.h gtk/widgets/Menubar/HelpMenuButton.cpp gtk/widgets/Menubar/HelpMenuButton.h gtk/widgets/Menubar/BluetoothMenuButton.cpp gtk/widgets/Menubar/BluetoothMenuButton.h gtk/PopUpWindow/HelpWindow.cpp gtk/PopUpWindow/HelpWindow.h bluetooth/BluetoothInterface.h bluetooth/Bluetooth.cpp bluetooth/Bluetooth.h gtk/PopUpWindow/BtWindow.cpp gtk/PopUpWindow/BtWindow.h)

target_link_libraries(${PROJECT_NAME} ${GSTREAMER_LIBRARIES} ${GTKMM_LIBRARIES} ${BLUEZ_LIBRARIES} ${X11_LIBRARIES} Threads::Threads )

add_executable(Google_Tests_run google-test/mocks/gtk/AppWindowMock.h google-test/tests/gtk/AppWindowTests.cpp gtk/RadioApp.cpp gtk/RadioApp.h gtk/AppWindow.cpp gtk/AppWindow.h gst/Player.cpp gst/Player.h links/Links.cpp links/Links.h gst/PlayerInterface.h gtk/AppWindowInterface.h links/LinksInterface.h EventHandler.cpp EventHandler.h gtk/widgets/Events/Event.h gtk/widgets/AppButton/AppButton.cpp gtk/widgets/AppButton/AppButton.h gtk/widgets/AppSlider/AppSlider.cpp gtk/widgets/AppSlider/AppSlider.h gtk/widgets/Menubar/Menubar.cpp gtk/widgets/Menubar/Menubar.h gtk/widgets/Menubar/FileMenuButton.cpp gtk/widgets/Menubar/FileMenuButton.h gtk/widgets/Events/Event.cpp gtk/PopUpWindow/PopUpWindowView.cpp gtk/PopUpWindow/PopUpWindowView.h gtk/PopUpWindow/PopUpWindowWrite.cpp gtk/PopUpWindow/PopUpWindowWrite.h gtk/PopUpWindow/PopUpWindow.cpp gtk/PopUpWindow/PopUpWindow.h Strategy/ClickedStrategy.h Strategy/PlayerClickedStrategy.cpp Strategy/PlayerClickedStrategy.h gtk/widgets/Events/Enums.h Strategy/MenubarClickedStrategy.cpp Strategy/MenubarClickedStrategy.h Strategy/PopUpWindowStrategy.cpp Strategy/PopUpWindowStrategy.h Strategy/SliderStrategy.cpp Strategy/SliderStrategy.h Strategy/StartupStrategy.cpp Strategy/StartupStrategy.h Strategy/BusMessageStrategy.cpp Strategy/BusMessageStrategy.h gst/PlayerEvent.cpp gst/PlayerEvent.h links/FileOperations.cpp links/FileOperations.h links/Validator.cpp links/Validator.h gtk/widgets/Menubar/HelpMenuButton.cpp gtk/widgets/Menubar/HelpMenuButton.h gtk/widgets/Menubar/BluetoothMenuButton.cpp gtk/widgets/Menubar/BluetoothMenuButton.h gtk/PopUpWindow/HelpWindow.cpp gtk/PopUpWindow/HelpWindow.h bluetooth/BluetoothInterface.h bluetooth/Bluetooth.cpp bluetooth/Bluetooth.h gtk/PopUpWindow/BtWindow.cpp gtk/PopUpWindow/BtWindow.h google-test/mocks/links/LinksMock.h google-test/mocks/gst/PlayerMock.h google-test/tests/gst/PlayerTests.cpp google-test/tests/links/linksTest.cpp)

target_link_libraries(Google_Tests_run gtest gtest_main gmock ${GSTREAMER_LIBRARIES} ${GTKMM_LIBRARIES} ${BLUEZ_LIBRARIES} ${X11_LIBRARIES} Threads::Threads)