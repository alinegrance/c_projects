#include <stdio.h>
#include <math.h>

int area_triangulo(int a, int b, int c){
    int sp = (a+b+c)/2;
    return sqrt(sp*(sp-a)*(sp-b)*(sp-c)); 
}

int main() {
    int a = 3;
    int b = 4;
    int c = 5;

    if((a < b + c) && (b < a + c) && c < (a + b)) {
        printf("Há um triangulo, de perimetro %d e area %d\n", a + b + c, area_triangulo(a, b, c)); 
 
    } else {
        printf("Não há um triangulo");
    }

    return 0;
}