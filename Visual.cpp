#include <math.h>
#include "graphics.hpp"
#include "Visual.hpp"
using namespace genv;

void Visual::grid() {
    gout << color(16,16,16) << move_to(0, 0) << box(S, S) << color(32,32,32);
    for (int i = 1; i < G; i++)
        gout << move_to(0, i*S/G - 1) << box(S, 2) <<
                move_to(i*S/G - 1, 0) << box(2, S);
}

void Visual::icon(char c, int lx, int ly, int s) {
    for (int i = 0; i <= s; i++)
        for (int j = 0; j <= s; j++) {
            int d = sqrt(pow(0.5*s - i, 2) + pow(0.5*s - j, 2));
            if (c == 'o' && 0.31*s < d && d < 0.5*s)
                gout << color(224,224,224) << move_to(lx + i, ly + j) << dot;
            if (c == 'x' && abs(i - j) < 0.15*s)
                gout << color(192,24,24) << move_to(lx + i, ly + j) << dot <<
                        move_to(lx + s - i, ly + j) << dot;
        }
}
