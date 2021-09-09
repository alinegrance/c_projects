#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void contador_de_troco(int troco, int trocos_disponiveis[], int trocos[], int i) {
    if (i == 7) {
        return;
    }

    trocos[i] = troco/trocos_disponiveis[i];
    troco %= trocos_disponiveis[i];

    i++;
    contador_de_troco(troco, trocos_disponiveis, trocos, i);
}


int main(int argc, char** argv) {
    int troco = atoi(argv[1]);

    int trocos[7]; // [numeros de notas de 100, ...]
    int trocos_disponiveis[7] = {100, 50, 20, 10, 5, 2, 1};

    contador_de_troco(troco, trocos_disponiveis, trocos, 0);

    for(int i = 0; i <= 6; i++) {
        printf("Notas de %d: %d\n", trocos_disponiveis[i], trocos[i]);
    }

    return 0;
}