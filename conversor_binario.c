#include <stdio.h>
#include <math.h> // -lm

int main() {

    int n;
    int i;
    int j;
    int n_decimal = 0;

    printf("entre o numero de bits:\n");
    scanf(" %d", &n);

    int array[n];

    printf("entre os bitis um a um:\n");

    for(i = 0; i < n; i++) {
        do {
            printf("entrando %d bit\n", i);
            scanf(" %d", &array[i]);
        } while((array[i] != 0) && (array[i] != 1));
    }

    for(i = 0, j = n - 1; i < n, j >= 0; i++, j--) {
        printf("i: %d, j: %d\n", i, j);
        n_decimal += (array[i]*pow(2,j));
    }

    printf("o numero em decimal é: %d\n", n_decimal);

    return 0;

}