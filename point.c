#include <stdio.h>

typedef struct point {
    int x;
    int y;
} POINT;

POINT set_x(POINT p, int new_x) {
    p.x = new_x;

    return p;
}

void main() {
    POINT p1;
    p1.x = 1;
    p1.y = 2;

    printf("(%d, %d)", p1.x, p1.y);

    p1 = set_x(p1, 10);

    printf("(%d, %d)", p1.x, p1.y);
}