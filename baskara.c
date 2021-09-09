#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void baskara(double a, double b, double c, double* x1, double* x2) {

    double delta = pow(b, 2) - (4*a*c);

    *x1 = (-b + sqrt(delta)) / (2*a);
    *x2 = (-b - sqrt(delta)) / (2*a);
}

int main(int argc, char* argv[]) {
    if(argc != 4) {
        return 1;
    }

    double a = strtod(argv[1], NULL);
    double b = strtod(argv[2], NULL);
    double c = strtod(argv[3], NULL);

    double x1, x2;

    baskara(a, b, c, &x1, &x2);

    printf("x1: %.2f\t x2: %.2f\n", x1, x2);

    return 0;
}