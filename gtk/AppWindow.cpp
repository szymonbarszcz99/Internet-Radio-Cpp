#include "AppWindow.h"

AppWindow::AppWindow(const Event& event)
:Gtk::ApplicationWindow(), eventForWidgets(event) {
    set_title("Internet Radio");
    //this->maximize();
    this->set_default_size(320, 240);

    this->grid =  std::make_unique<Gtk::Grid>();
    //this->grid->property_expand() = true;
    add(*(this->grid));

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

    this->label = std::make_unique<Gtk::Label>("");
    this->label->property_margin() = 10;
    this->songNameLabel = std::make_unique<Gtk::Label>("");
    this->songNameLabel->property_margin() = 10;
    return this;
}

AppWindow *AppWindow::attachWidgets() {
    this->grid->attach(*this->menubar,0,0,4);

    this->grid->attach(*this->label,0,1,4);
    this->grid->attach(*this->songNameLabel,0,2,4);

    this->grid->attach(*this->pauseButton1, 2,3,1);
    this->grid->attach(*this->playButton1,1,3,1);
    this->grid->attach(*this->previousButton,0,3,1);
    this->grid->attach(*this->nextButton,3,3,1);
    this->grid->attach(*this->appSlider,0,4,4);

    //this->grid->show_all();

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
    auto popUpWindow2 = std::make_shared<PopUpWindowWrite>(windowName,nameEntry,linkEntry,eventForWidgets, windowAction);
    this->showWindow(popUpWindow2);
}

AppWindow::~AppWindow() {
    std::cout<<"AppWindow Destructor"<<std::endl;
    //this->eventForWidgets.reset();
}

void AppWindow::throwModal(int lineNumber, std::string text) {
    if(lineNumber > 0){
        Gtk::MessageDialog linkError("Error at line: " + std::to_string(lineNumber) + ":\n" + text + "\n" + "Skipping this line");
        linkError.run();
    }
    else{
        Gtk::MessageDialog linkError(text);
        linkError.run();
    }
}

void AppWindow::startupCheckLinks() {
    this->eventForWidgets.onStartup();
}

void AppWindow::updateSongNameLabel(const std::string &songName) {
    this->songNameLabel->set_label(songName);
}

void AppWindow::showWindow(std::shared_ptr<Gtk::Window> windowToShow) {
    this->windowToShow = windowToShow;
    this->windowToShow->present();
}

void AppWindow::closeWindow() {
    this->windowToShow->close();
}



