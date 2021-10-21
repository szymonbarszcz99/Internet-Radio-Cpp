#include "AppWindow.h"
#include "PopUpWindow/PopUpWindow.h"

AppWindow::AppWindow(EventHandler* eventHandler):Gtk::ApplicationWindow() {
    set_title("Internet Radio");

    this->grid = new WidgetGrid();
    add(*(this->grid));

    this->eventForWidgets = new Event(eventHandler);

    this->createLabel()->createButtons()->createSlider()->createMenubar()->attachWidgets();
}

void AppWindow::updateLabel(const std::string &newStation) {
    this->appLabel->style(newStation);
}

AppWindow *AppWindow::createButtons() {
    ButtonConstructor buttonConstructor;

    this->playButton1 = buttonConstructor.FactoryMethod(eventForWidgets, PLAY);
    this->playButton1->style("media-playback-start");

    this->pauseButton1 = buttonConstructor.FactoryMethod(eventForWidgets, PAUSE);
    this->pauseButton1->style("media-playback-pause");

    this->previousButton = buttonConstructor.FactoryMethod(eventForWidgets,PREVIOUS);
    this->previousButton->style("media-seek-backward");

    this->nextButton = buttonConstructor.FactoryMethod(eventForWidgets,NEXT);
    this->nextButton->style("media-seek-forward");

    return this;
}

AppWindow *AppWindow::createLabel() {
    LabelConstructor labelConstructor;

    this->appLabel = labelConstructor.FactoryMethod(eventForWidgets);
    this->appLabel->style("Hello world");

    return this;
}

AppWindow *AppWindow::attachWidgets() {
    this->grid->attach(*this->menubar,0,0,4);

    this->grid->attach(*this->appLabel->getAppWidget(),0,1,4);

    this->grid->attach(*this->pauseButton1->getAppWidget(), 2,2,1);
    this->grid->attach(*this->playButton1->getAppWidget(),1,2,1);
    this->grid->attach(*this->previousButton->getAppWidget(),0,2,1);
    this->grid->attach(*this->nextButton->getAppWidget(),3,2,1);
    this->grid->attach(*this->appSlider->getAppWidget(),0,3,4);

    this->grid->show_all();

    return this;
}

AppWindow *AppWindow::createSlider() {
    this->appSlider = new AppSlider(eventForWidgets);
    this->appSlider->style("audio-volume-high");

    return this;
}

AppWindow *AppWindow::createMenubar() {
    this->menubar = new Menubar();
    this->menubar->createFileMenuButton(eventForWidgets);
    this->menubar->createViewStationButton(eventForWidgets);
    return this;
}

void AppWindow::createPopUpWindow(const std::vector<Stations>& stations) {
    this->popUpWindow = new PopUpWindow();
    this->popUpWindow->set_title("Stations");

    Gtk::Grid* windowGrid = new Gtk::Grid();
    this->popUpWindow->add(*windowGrid);

    int i=0;
    for(auto it: stations){
        Gtk::Label* name = new Gtk::Label();
        Gtk::Label* link = new Gtk::Label();

        name->set_text(it.StationName);
        link->set_text(it.StationLink);

        windowGrid->attach(*name,0,i);
        windowGrid->attach(*link,1,i++);
    }

    this->popUpWindow->show_all();
}


