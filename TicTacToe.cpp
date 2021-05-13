#include <math.h>
#include <windows.h>
#include "graphics.hpp"
#include "TicTacToe.hpp"
using namespace genv;

TicTacToe::TicTacToe() {
    memset(cells, ' ', sizeof(cells));
    event_loop();
}

void TicTacToe::draw() {
    v.grid();
    if (game_over()) {
        v.icon(winner, 0, 0, S);
        gout << refresh;
        Sleep(3000);
    }
    else {
        for (int h = 0; h < G; h++)
            for (int w = 0; w < G; w++)
                v.icon(cells[h][w], w*S/G + 1, h*S/G + 1, S/G - 3);
        gout << refresh;
    }
}

void TicTacToe::handle(event ev) {
    int h = floor(G*ev.pos_y/S);
    int w = floor(G*ev.pos_x/S);
    if (ev.button == btn_left && cells[h][w] == ' ') {
        next_icon = (next_icon != 'o')*'o' + (next_icon != 'x')*'x';
        cells[h][w] = next_icon;
    }
}

bool TicTacToe::winning_pos(int h, int w) {
    if (cells[h][w] == ' ') return false;
    bool paths[4] = {1, 1, 1, 1};
    for (int i = 1; i < 5; i++) {
        if (G-5 < w || cells[h][w+i] != cells[h][w]) paths[0] = 0;
        if (G-5 < h || cells[h+i][w] != cells[h][w]) paths[1] = 0;
        if (G-5 < h || G-5 < w || cells[h+i][w+i] != cells[h][w]) paths[2] = 0;
        if (h < 4 || G-5 < w || cells[h-i][w+i] != cells[h][w]) paths[3] = 0;
    }
    return paths[0] || paths[1] || paths[2] || paths[3];
}

bool TicTacToe::game_over() {
    bool is_full = 1;
    for (int h = 0; h < G; h++)
        for (int w = 0; w < G; w++) {
            if (cells[h][w] == ' ') is_full = false;
            if (winning_pos(h, w)) winner = cells[h][w];
        }
    return is_full || winner != ' ';
}

void TicTacToe::event_loop() {
    gout.open(S, S);
    event ev;
    while (gin >> ev && ev.keycode != key_escape) {
        handle(ev);
        draw();
        if (game_over()) break;
    }
}
