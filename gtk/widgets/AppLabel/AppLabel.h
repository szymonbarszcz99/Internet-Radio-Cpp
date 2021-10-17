#ifndef UNTITLED2_APPLABEL_H
#define UNTITLED2_APPLABEL_H
#include <gtkmm/label.h>
#include "../AppWidget/AppWidget.h"

class AppLabel : public AppWidget{
    Event* properEvent;
    Gtk::Label appWidget;
public:
    void style(std::string styleString);
    void onClicked() override;
    AppLabel(Event* properEvent);
    Gtk::Widget* getAppWidget() override;
};


#endif //UNTITLED2_APPLABEL_H
