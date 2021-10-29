#include "AppWindow.h"

//TODO 1. Delete factory. OK
//TODO 2. Replace AppLabel with ordinary Label that doesn't connect to event. OK
//TODO 3. Make button with constructor that connects callbacks. OK
//TODO 4. Remove that weird,ugly AppWidget interface. It only complicates. OK
//TODO 5. Builder for AppWindow widgets ? No, now methods have only few lines.
//TODO 6. Attach ?
//TODO 7. Make Slider. Just simple Slider. OK
//TODO 8. Menubar build itself, not delegates it to AppWindow. OK
//TODO 9. Builder for PopUpWindow1 and 2. OK
//TODO 10. Divide EventHandler, it's too big. Apply Strategy design pattern  OK
//TODO 11. Make something with these pop ups "purpose" field. It should be nicer. OK
//TODO 12. Look for places for Lambdas.
//TODO 13. Structured bindings may be useful. Maybe not.
//TODO 14. Apply smart pointers OK
//TODO 15. Get rid of WidgetGrid and replace it with ordinary Grid. OK


AppWindow::AppWindow(std::unique_ptr<EventHandler> eventHandler,std::shared_ptr<PlayerClickedStrategy> clickedStrategy,
                     std::shared_ptr<MenubarClickedStrategy> menubarClickedStrategy, std::shared_ptr<PopUpWindowStrategy> popUpWindowStrategy,
                     std::shared_ptr<SliderStrategy> sliderStrategy)
:Gtk::ApplicationWindow() {
    set_title("Internet Radio");

    this->grid =  std::make_unique<Gtk::Grid>();
    add(*(this->grid));

    this->eventForWidgets = std::make_shared<Event>(std::move(eventHandler),clickedStrategy,menubarClickedStrategy,popUpWindowStrategy,sliderStrategy);

    this->createLabel()->createButtons()->createSlider()->createMenubar()->attachWidgets();
}

void AppWindow::updateLabel(const std::string &newStation) {
    this->label->set_label(newStation);
}

AppWindow *AppWindow::createButtons() {

    this->playButton1 = std::make_unique<AppButton>(eventForWidgets, PLAY);

    this->pauseButton1 = std::make_unique<AppButton>(eventForWidgets, PAUSE);

    this->previousButton = std::make_unique<AppButton>(eventForWidgets,PREVIOUS);

    this->nextButton = std::make_unique<AppButton>(eventForWidgets,NEXT);

    return this;
}

AppWindow *AppWindow::createLabel() {

    this->label = std::make_unique<Gtk::Label>("Hello world");
    this->label->property_margin() = 10;
    return this;
}

AppWindow *AppWindow::attachWidgets() {
    this->grid->attach(*this->menubar,0,0,4);

    this->grid->attach(*this->label,0,1,4);

    this->grid->attach(*this->pauseButton1, 2,2,1);
    this->grid->attach(*this->playButton1,1,2,1);
    this->grid->attach(*this->previousButton,0,2,1);
    this->grid->attach(*this->nextButton,3,2,1);
    this->grid->attach(*this->appSlider,0,3,4);

    this->grid->show_all();

    return this;
}

AppWindow *AppWindow::createSlider() {
    this->appSlider = std::make_unique<AppSlider>(eventForWidgets);

    return this;
}

AppWindow *AppWindow::createMenubar() {
    this->menubar = std::make_unique<Menubar>(eventForWidgets);
    return this;
}

void AppWindow::createPopUpWindowView(const std::vector<Stations>& stations) {
    this->popUpWindowView = std::make_unique<PopUpWindowView>("Stations");

    for(const auto& it: stations){
        popUpWindowView->populate(it.StationName,it.StationLink);
    }

    this->popUpWindowView->show_all();
}

void AppWindow::createPopUpWindowWrite(std::string windowName,std::string nameEntry, std::string linkEntry) {
    Actions windowAction;
    if(windowName == "Add")windowAction = ADD_STATION;
    else windowAction = MODIFY_STATION;
    this->popUpWindow2 = std::make_unique<PopUpWindowWrite>(windowName,nameEntry,linkEntry,eventForWidgets, windowAction);
    this->popUpWindow2->show_all();
}

AppWindow::~AppWindow() {
    std::cout<<"AppWindow Destructor"<<std::endl;
    //this->eventForWidgets.reset();
}



