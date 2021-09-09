#include <stdio.h>

int main() {
    int troco = 188; 
    int n_cem = 0; 
    int n_cinquenta = 0;
    int n_vinte = 0;
    int n_dez = 0; 
    int n_cinco = 0;
    int n_dois = 0;
    int n_um = 0;

    int trocos[7]; // [numeros de notas de 100, ...]
    int trocos_disponiveis[7] = {100, 50, 20, 10, 5, 2, 1};
    
    for(int i = 0; i <= 6; i++) {
        trocos[i] = troco/trocos_disponiveis[i];
        troco %= trocos_disponiveis[i];
    }

    for(int i = 0; i <= 6; i++) {
        printf("Notas de %d: %d\n", trocos_disponiveis[i], trocos[i]);
    }
}