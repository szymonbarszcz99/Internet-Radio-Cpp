#include "AppWindow.h"

AppWindow::AppWindow(EventHandler* eventHandler):Gtk::ApplicationWindow() {
    set_title("Internet Radio");

    this->grid = new WidgetGrid();
    add(*(this->grid));

    this->stationName = new StationName();
    this->grid->attach(*this->stationName,0,0,4);

    Event* eventClicked = new EventClicked(eventHandler);

    this->previousButton = new ButtonFactory("media-seek-backward", eventClicked, PREVIOUS);
    this->grid->attach(*this->previousButton,0,1,1,1);

    this->playButton = new ButtonFactory("media-playback-start", eventClicked, PLAY);
    this->grid->attach(*this->playButton,1,1,1,1);

    this->pauseButton = new ButtonFactory("media-playback-pause", eventClicked, PAUSE);
    this->grid->attach(*this->pauseButton,2,1,1,1);

    this->nextButton = new ButtonFactory("media-seek-forward", eventClicked, NEXT);
    this->grid->attach(*this->nextButton,3,1,1,1);

    this->grid->show_all();
}

void AppWindow::updateLabel(const std::string &newStation) {
    this->stationName->set_text(newStation);
}


