#include <stdio.h>

int fatorial(int n) {
    if(n == 0){
        return 1;
    } else{
        return n * fatorial(n-1);
    }
}

void divisor(int n) {
    if(n == 0) {
        printf("nao ha divisores para 0");
    } else {
        printf("%d é divisor de %d\n", n, n);
        for(int i = (n/2); i > 0; i--){
            if(n%i == 0) {
               printf("%d é divisor de %d\n", i, n);
            }
        }
    }
}

int main() {
    int n = 10;

    printf("Fatorial de %d é %d\n", n, fatorial(n));
    divisor(n);

    return 0;
}

