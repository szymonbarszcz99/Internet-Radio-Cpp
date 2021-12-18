#ifndef UNTITLED2_HELPWINDOW_H
#define UNTITLED2_HELPWINDOW_H
#include <gtkmm/window.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/textview.h>

class HelpWindow : public Gtk::Window{

    Gtk::ScrolledWindow scrolledWindow;
    Gtk::TextView textView;
    Glib::RefPtr<Gtk::TextBuffer> textBuffer;

public:
    HelpWindow(): Gtk::Window(){
        this->set_title("Help");

        scrolledWindow.add(textView);
        scrolledWindow.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_AUTOMATIC);

        textBuffer = Gtk::TextBuffer::create();
        textBuffer->set_text("");

        textView.set_buffer(textBuffer);
        textView.set_editable(false);

        this->add(scrolledWindow);
        this->maximize();
        show_all();
    }

    void setBuffer(const std::string& textToSet);

};


#endif //UNTITLED2_HELPWINDOW_H
