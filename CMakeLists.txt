cmake_minimum_required(VERSION 3.16)
project(untitled2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(PkgConfig)
find_package(Threads REQUIRED)

pkg_check_modules(GSTREAMER REQUIRED gstreamer-1.0)
pkg_check_modules(GTKMM REQUIRED gtkmm-3.0)
include_directories(
        ${GLIB_INCLUDE_DIRS}
        ${GSTREAMER_INCLUDE_DIRS}
        ${GTKMM_INCLUDE_DIRS}
)
link_directories(
        ${GLIB_LIBRARY_DIRS}
        ${GSTREAMER_LIBRARY_DIRS}
        ${GTKMM_LIBRARY_DIRS}
)


add_executable(untitled2 main.cpp gtk/RadioApp.cpp gtk/RadioApp.h gtk/AppWindow.cpp gtk/AppWindow.h gtk/widgets/WidgetGrid/WidgetGrid.cpp gtk/widgets/WidgetGrid/WidgetGrid.h gst/Player.cpp gst/Player.h links/Links.cpp links/Links.h gst/PlayerInterface.h gtk/AppWindowInterface.h links/LinksInterface.h EventHandler.cpp EventHandler.h gtk/widgets/Buttons/Events/Event.h gtk/widgets/AppWidget/AppWidget.cpp gtk/widgets/AppWidget/AppWidget.h gtk/widgets/AppButton/AppButton.cpp gtk/widgets/AppButton/AppButton.h gtk/widgets/AppLabel/AppLabel.cpp gtk/widgets/AppLabel/AppLabel.h gtk/widgets/WidgetConstructor/WidgetConstructor.cpp gtk/widgets/WidgetConstructor/WidgetConstructor.h gtk/widgets/WidgetConstructor/ButtonConstructor.cpp gtk/widgets/WidgetConstructor/ButtonConstructor.h gtk/widgets/WidgetConstructor/LabelConstructor.cpp gtk/widgets/WidgetConstructor/LabelConstructor.h gtk/widgets/Buttons/Events/EventClicked.cpp gtk/widgets/Buttons/Events/EventClicked.h gtk/widgets/AppSlider/AppSlider.cpp gtk/widgets/AppSlider/AppSlider.h gtk/widgets/Buttons/Events/EventValueChanged.cpp gtk/widgets/Buttons/Events/EventValueChanged.h gtk/widgets/WidgetConstructor/SliderConstructor.cpp gtk/widgets/WidgetConstructor/SliderConstructor.h)


target_link_libraries(${PROJECT_NAME} ${GSTREAMER_LIBRARIES} ${GTKMM_LIBRARIES} Threads::Threads)