#include "graphics.hpp"
#include "Square.hpp"
#include "Widget.hpp"
using namespace genv;

char Square::next = 'x';

Square::Square(int lx, int ly, int s) :
Widget(lx, ly, s, s), val(' '), s(s) {}

char Square::get_val() {
    return val;
}

void Square::draw() {
    Widget::draw();
    v.icon(val, lx+1, ly+1, s-2);
}

void Square::handle(event ev) {
    if (is_selected(ev.pos_x,ev.pos_y) && ev.button == btn_left && val == ' ') {
        val = next;
        if (next == 'x') next = 'o';
        else if (next == 'o') next = 'x';
    }
}
