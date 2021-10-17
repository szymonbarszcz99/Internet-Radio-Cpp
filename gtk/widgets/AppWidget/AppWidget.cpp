#include "AppWidget.h"

void AppWidget::applyMargin(Gtk::Widget& widgetToApply) {
    widgetToApply.set_margin_start(10);
    widgetToApply.set_margin_end(10);
    widgetToApply.set_margin_top(10);
    widgetToApply.set_margin_bottom(10);
}
