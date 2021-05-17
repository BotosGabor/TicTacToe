#ifndef SCREEN_HPP_INCLUDED
#define SCREEN_HPP_INCLUDED

#include <vector>
#include "Widget.hpp"

class Screen {
    std::vector <Widget*> widgets;
public:
    Screen();
    void append(Widget* w);
    void event_loop();
};

extern const int X, Y;
extern Screen* S;

#endif // SCREEN_HPP_INCLUDED
