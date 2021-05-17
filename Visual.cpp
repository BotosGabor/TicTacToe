#include <math.h>
#include "graphics.hpp"
#include "Visual.hpp"
using namespace genv;

void Visual::background(int lx, int ly, int sx, int sy) {
    gout << color(32,32,32) << move_to(lx,ly) << box(sx,sy) <<
            color(16,16,16) << move_to(lx+1, ly+1) << box(sx-2, sy-2);
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
