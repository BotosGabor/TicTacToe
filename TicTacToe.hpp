#ifndef GAME_FIELD_HPP_INCLUDED
#define GAME_FIELD_HPP_INCLUDED

#include "graphics.hpp"
#include "Visual.hpp"

class TicTacToe {
    Visual v;
    char cells[G][G];
    char next_icon = 'o';
    char winner = ' ';
    void draw();
    void handle(genv::event ev);
    bool winning_pos(int x, int y);
    bool game_over();
    void event_loop();
public:
    TicTacToe();
};

#endif // GAME_FIELD_HPP_INCLUDED
