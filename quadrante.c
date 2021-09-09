#include <stdio.h>

int main() {
    int x=10; 
    int y=-10;

    if(x>0 && y>0) {
        printf("quadrante 1\n");
    }

    if(x<0 && y>0) {
        printf("quadrante 2\n");
    }

    if(x<0 && y<0) {
        printf("quadrante 3\n");
    }

    if(x>0 && y<0) {
        printf("quadrante 4\n");
    }

    return 0;
}