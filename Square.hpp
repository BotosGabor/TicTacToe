#ifndef SQUARE_HPP_INCLUDED
#define SQUARE_HPP_INCLUDED

#include "graphics.hpp"
#include "Widget.hpp"

class Square : public Widget {
    static char next;
    char val;
    int s;
public:
    Square(int lx, int ly, int s);
    char get_val();
    virtual void draw();
    virtual void handle(genv::event ev);
};

#endif // SQUARE_HPP_INCLUDED
