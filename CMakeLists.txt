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

add_executable(untitled2 main.cpp gtk/RadioApp.cpp gtk/RadioApp.h gtk/AppWindow.cpp gtk/AppWindow.h)

target_link_libraries(${PROJECT_NAME} ${GSTREAMER_LIBRARIES} ${GTKMM_LIBRARIES} Threads::Threads)