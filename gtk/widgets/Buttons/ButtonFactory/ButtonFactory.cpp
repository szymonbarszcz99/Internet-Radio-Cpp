#include "ButtonFactory.h"

ButtonFactory::ButtonFactory(const char* icon):Gtk::Button() {
    set_image_from_icon_name(icon);
    set_margin_start(10);
    set_margin_end(10);
    set_margin_top(10);
    set_margin_bottom(10);
}