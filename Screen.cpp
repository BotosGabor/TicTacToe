#include "graphics.hpp"
#include "Screen.hpp"
using namespace genv;
using namespace std;

const int X = 1050;
const int Y = 1050;
Screen* S = new Screen();

Screen::Screen() {
    gout.open(X, Y);
}

void Screen::append(Widget* w) {
    widgets.push_back(w);
}

void Screen::event_loop() {
    event ev;
    int focus = -1;
    for (Widget* w : widgets) w->draw();
    gout << refresh;
    while (gin >> ev && ev.keycode != key_escape) {
        if (ev.button == btn_left)
            for (size_t i = 0; i < widgets.size(); i++)
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) focus = i;
        if (focus != -1) widgets[focus]->handle(ev);
        for (Widget* w : widgets) w->draw();
        gout << refresh;
    }
}
