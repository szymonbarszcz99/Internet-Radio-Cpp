#include "AppWindow.h"
#include "widgets/WidgetConstructor/ButtonConstructor.h"
#include "widgets/WidgetConstructor/LabelConstructor.h"
#include "widgets/Buttons/Events/EventClicked.h"

AppWindow::AppWindow(EventHandler* eventHandler):Gtk::ApplicationWindow() {
    set_title("Internet Radio");

    this->grid = new WidgetGrid();
    add(*(this->grid));

    LabelConstructor labelConstructor;

    Event* clickedEvent = new EventClicked(eventHandler);

    this->appLabel = labelConstructor.FactoryMethod(clickedEvent);
    this->appLabel->style("Hello world");
    this->grid->attach(*this->appLabel->getAppWidget(),0,0);

    ButtonConstructor buttonConstructor;

    this->playButton1 = buttonConstructor.FactoryMethod(clickedEvent, PLAY);
    this->playButton1->style("media-playback-start");
    this->grid->attach(*this->playButton1->getAppWidget(),0,1);

    this->pauseButton1 = buttonConstructor.FactoryMethod(clickedEvent, PAUSE);
    this->pauseButton1->style("media-playback-pause");
    this->grid->attach(*this->pauseButton1->getAppWidget(), 1,1);

    this->grid->show_all();
}

void AppWindow::updateLabel(const std::string &newStation) {
    this->appLabel->style(newStation);
}


