#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED

#include "graphics.hpp"
#include "Visual.hpp"

class Widget {
protected:
    int lx, ly, sx, sy;
    Visual v;
public:
    Widget(int lx, int ly, int sx, int sy);
    virtual void draw();
    virtual bool is_selected(int mx, int my);
    virtual void handle(genv::event ev) = 0;
};

#endif // WIDGET_HPP_INCLUDED
