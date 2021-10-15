#include "AppWindow.h"

AppWindow::AppWindow(EventHandler* eventHandler):Gtk::ApplicationWindow() {
    set_title("Internet Radio");

    this->grid = new WidgetGrid();
    add(*(this->grid));

    this->stationName = new StationName();
    this->grid->attach(*this->stationName,0,0,4);

    Event* eventPrevious = new EventClicked(PREVIOUS,eventHandler);
    this->previousButton = new ButtonFactory("media-seek-backward", eventPrevious);
    this->grid->attach(*this->previousButton,0,1,1,1);

    Event* eventPlay = new EventClicked(PLAY,eventHandler);
    this->playButton = new ButtonFactory("media-playback-start", eventPlay);
    this->grid->attach(*this->playButton,1,1,1,1);

    Event* eventPause = new EventClicked(PAUSE,eventHandler);
    this->pauseButton = new ButtonFactory("media-playback-pause", eventPause);
    this->grid->attach(*this->pauseButton,2,1,1,1);

    Event* eventNext = new EventClicked(NEXT,eventHandler);
    this->nextButton = new ButtonFactory("media-seek-forward", eventNext);
    this->grid->attach(*this->nextButton,3,1,1,1);

    this->grid->show_all();
}

void AppWindow::updateLabel(const std::string &newStation) {
    this->stationName->set_text(newStation);
}


