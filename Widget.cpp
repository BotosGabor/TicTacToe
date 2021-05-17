#include "Widget.hpp"
#include "Screen.hpp"
using namespace genv;

Widget::Widget(int lx, int ly, int sx, int sy) :
lx(lx), ly(ly), sx(sx), sy(sy) {
    S->append(this);
}

void Widget::draw() {
    v.background(lx, ly, sx, sy);
}

bool Widget::is_selected(int mx, int my) {
    return lx < mx && mx < lx + sx && ly < my && my < ly + sy;
}
