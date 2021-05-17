#include <iostream>
#include <math.h>
#include <windows.h>
#include "graphics.hpp"
#include "Screen.hpp"
#include "TicTacToe.hpp"
using namespace genv;
using namespace std;

TicTacToe::TicTacToe() :
Widget(0, 0, X, Y), s(X) {
    for (int h = 0; h < G; h++)
        for (int w = 0; w < G; w++)
            squares[h][w] = new Square(lx + w*s/G, ly + h*s/G, s/G);
}

void TicTacToe::draw() {
    if (game_over()) {
        if (winner == ' ') cout << "Draw!\n\n";
        else cout << "Winner: " << winner << "!\n\n";
        for (int h = 0; h < G; h++) {
            for (int w = 0; w < G; w++)
                if (squares[h][w]->get_val() == ' ') cout << "- ";
                else cout << squares[h][w]->get_val() << ' ';
            cout << "\n";
        }
        cout << endl;
        v.background(0,0,X,Y);
        v.icon(winner, lx, ly, s);
        gout << refresh;
        Sleep(3000);
        exit(0);
    }
}

void TicTacToe::handle(event ev) {}

bool TicTacToe::winning_pos(int h, int w) {
    if (squares[h][w]->get_val() == ' ') return false;
    bool paths[4] = {1, 1, 1, 1};
    for (int i = 1; i < 5; i++) {
        if (G-5 < w || squares[h][w+i]->get_val() !=
            squares[h][w]->get_val()) paths[0] = 0;
        if (G-5 < h || squares[h+i][w]->get_val() !=
            squares[h][w]->get_val()) paths[1] = 0;
        if (G-5 < h || G-5 < w || squares[h+i][w+i]->get_val() !=
            squares[h][w]->get_val()) paths[2] = 0;
        if (h < 4 || G-5 < w || squares[h-i][w+i]->get_val() !=
            squares[h][w]->get_val()) paths[3] = 0;
    }
    return paths[0] || paths[1] || paths[2] || paths[3];
}

bool TicTacToe::game_over() {
    bool is_full = 1;
    for (int h = 0; h < G; h++)
        for (int w = 0; w < G; w++) {
            if (squares[h][w]->get_val() == ' ') is_full = false;
            if (winning_pos(h, w)) winner = squares[h][w]->get_val();
        }
    return is_full || winner != ' ';
}
