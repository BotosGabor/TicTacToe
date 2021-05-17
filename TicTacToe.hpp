#ifndef TICTACTOE_HPP_INCLUDED
#define TICTACTOE_HPP_INCLUDED

#include "graphics.hpp"
#include "Square.hpp"
#include "Widget.hpp"

const int G = 30;

class TicTacToe : public Widget {
    int s;
    Square* squares[G][G];
    char winner = ' ';
    bool winning_pos(int x, int y);
    bool game_over();
public:
    TicTacToe();
    void draw();
    void handle(genv::event ev);
};

#endif // TICTACTOE_HPP_INCLUDED
