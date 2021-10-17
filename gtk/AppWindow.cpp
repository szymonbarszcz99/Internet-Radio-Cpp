#include "AppWindow.h"
#include "widgets/WidgetConstructor/ButtonConstructor.h"
#include "widgets/Buttons/Events/PlayEvent.h"
#include "widgets/Buttons/Events/PauseEvent.h"
#include "widgets/WidgetConstructor/LabelConstructor.h"
#include "widgets/Buttons/Events/LabelEvent.h"

AppWindow::AppWindow(EventHandler* eventHandler):Gtk::ApplicationWindow() {
    set_title("Internet Radio");

    this->grid = new WidgetGrid();
    add(*(this->grid));
    LabelConstructor labelConstructor;

    Event* labelEvent = new LabelEvent(eventHandler);
    this->appLabel = labelConstructor.FactoryMethod(labelEvent);
    this->appLabel->style("Hello world");
    this->grid->attach(*this->appLabel->getAppWidget(),0,0);

    /*this->stationName = new StationName();
    this->grid->attach(*this->stationName,0,0,4);*/

    ButtonConstructor buttonConstructor;

    Event* playButtonEvent = new PlayEvent(eventHandler);
    this->playButton1 = buttonConstructor.FactoryMethod(playButtonEvent);
    this->playButton1->style("media-playback-start");
    this->grid->attach(*this->playButton1->getAppWidget(),0,1);

    Event* pauseButtonEvent = new PauseEvent(eventHandler);
    this->pauseButton1 = buttonConstructor.FactoryMethod(pauseButtonEvent);
    this->pauseButton1->style("media-playback-pause");
    this->grid->attach(*this->pauseButton1->getAppWidget(), 1,1);

    /*Event* eventClicked = new EventClicked(eventHandler);

    this->previousButton = new ButtonFactory("media-seek-backward", eventClicked, PREVIOUS);
    this->grid->attach(*this->previousButton,0,1,1,1);

    this->playButton = new ButtonFactory("media-playback-start", eventClicked, PLAY);
    this->grid->attach(*this->playButton,1,1,1,1);

    this->pauseButton = new ButtonFactory("media-playback-pause", eventClicked, PAUSE);
    this->grid->attach(*this->pauseButton,2,1,1,1);

    this->nextButton = new ButtonFactory("media-seek-forward", eventClicked, NEXT);
    this->grid->attach(*this->nextButton,3,1,1,1);
std::cout<<"zrobilem grida"<<std::endl;

     */

    this->grid->show_all();
}

void AppWindow::updateLabel(const std::string &newStation) {
    this->appLabel->style(newStation);
}


