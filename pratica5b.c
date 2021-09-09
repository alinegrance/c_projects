#include <stdio.h>
#include <math.h>

double f(double x) {
    return pow(x, 2) - 228;
}

double f_linha(double x) {
    return 2 * x;
}

double iteracao(double a) {
    return a - f(a)/f_linha(a);
}

int main() {

    double tolerancia = 0.00001;
    double x = 11;
    double aux;
    int it = 0;
    
    do {
        aux = x;
        x = iteracao(x); 
        it++;
        printf("%d: %.12lf\n", it, x);

    } while (fabs(x-aux) >= 0.00001);

    return 0;

}