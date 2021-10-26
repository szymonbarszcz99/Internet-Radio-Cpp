#include "AppWindow.h"
#include "PopUpWindow/PopUpWindow.h"

//TODO 1. Delete factory. OK
//TODO 2. Replace AppLabel with ordinary Label that doesn't connect to event. OK
//TODO 3. Make button with constructor that connects callbacks. OK
//TODO 4. Remove that weird,ugly AppWidget interface. It only complicates. OK
//TODO 5. Builder for AppWindow widgets ?
//TODO 6. Attach ?
//TODO 7. Make Slider. Just simple Slider. OK
//TODO 8. Menubar build itself, not delegates it to AppWindow.
//TODO 9. Builder for PopUpWindow1 and 2.
//TODO 10. Divide EventHandler, it's too big.
//TODO 11. Make something with these pop ups "purpose" field. It should be nicer.
//TODO 12. Look for places for Lambdas.
//TODO 13. Structured bindings may be useful.
//TODO 14. Apply smart pointers


AppWindow::AppWindow(EventHandler* eventHandler):Gtk::ApplicationWindow() {
    set_title("Internet Radio");

    this->grid = new WidgetGrid();
    add(*(this->grid));

    this->eventForWidgets = new Event(eventHandler);

    this->createLabel()->createButtons()->createSlider()->createMenubar()->attachWidgets();
}

void AppWindow::updateLabel(const std::string &newStation) {
    this->label->set_label(newStation);
}

AppWindow *AppWindow::createButtons() {

    this->playButton1 = new AppButton(eventForWidgets, PLAY);

    this->pauseButton1 = new AppButton(eventForWidgets, PAUSE);

    this->previousButton = new AppButton(eventForWidgets,PREVIOUS);

    this->nextButton = new AppButton(eventForWidgets,NEXT);

    return this;
}

AppWindow *AppWindow::createLabel() {

    this->label = new Gtk::Label("Hello world");
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
    this->appSlider = new AppSlider(eventForWidgets);

    return this;
}

AppWindow *AppWindow::createMenubar() {
    this->menubar = new Menubar();
    this->menubar->createFileMenuButton(eventForWidgets);
    this->menubar->createViewStationButton(eventForWidgets);
    return this;
}

void AppWindow::createPopUpWindow(const std::vector<Stations>& stations) {
    this->popUpWindow = new PopUpWindow("Stations");

    int i=0;
    for(auto it: stations){
        Gtk::Label* name = new Gtk::Label(it.StationName);
        Gtk::Label* link = new Gtk::Label(it.StationLink);

        popUpWindow->populate(name,0,i);
        popUpWindow->populate(link,1,i++);
    }

    this->popUpWindow->show_all();
}

void AppWindow::createPopUpWindow2(std::string nameEntry, std::string linkEntry) {
    this->popUpWindow2 = new PopUpWindow2("Add",nameEntry,linkEntry,eventForWidgets);
    this->popUpWindow2->show_all();
}


