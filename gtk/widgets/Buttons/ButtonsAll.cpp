#include "ButtonsAll.h"

ButtonsAll::ButtonsAll() {
    Gtk::Button* previousStationButton = new ButtonFactory("media-seek-backward");
    this->ButtonVector.push_back(previousStationButton);

    Gtk::Button* playButton = new ButtonFactory("media-playback-start");
    this->ButtonVector.push_back(playButton);

    Gtk::Button* pauseButton = new ButtonFactory("media-playback-pause");
    this->ButtonVector.push_back(pauseButton);

    Gtk::Button* nextStationButton = new ButtonFactory("media-seek-forward");
    this->ButtonVector.push_back(nextStationButton);
}

const std::vector<Gtk::Button*>& ButtonsAll::getVector(){
    return this->ButtonVector;
}