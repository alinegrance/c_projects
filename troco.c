#include <stdio.h>
#include <math.h>

int main() {

    int valor_da_compra = 579;
    int valor_recebido = 600;
    int troco = valor_recebido - valor_da_compra;
    int n_cem = 0; 
    int n_cinquenta = 0;
    int n_vinte = 0;
    int n_dez = 0; 
    int n_cinco = 0;
    int n_dois = 0;
    int n_um = 0;

    if(troco >= 100) {
        n_cem = troco/100;
        troco %= 100;
    }
    
    if(troco >= 50) {
        n_cinquenta = troco/50;
        troco %= 50;
    }
    
    if(troco >= 20) {
        n_vinte = troco/20;
        troco %= 20;
    }
    
    if(troco >= 10) {
        n_dez = troco/10;
        troco %= 10;
    }
    
    if(troco >= 5) {
        n_cinco = troco/5;
        troco %= 50;
    }

    if(troco >= 2) {
        n_dois = troco/2;
        troco %= 2;
    }
    
    if(troco > 0) {
        n_um = troco;
    }

    printf("Troco: %d, com %d notas de 100, %d notas de 50, %d notas de 20, %d notas de 10, %d notas de 5 e %d notas de 1\n", troco, n_cem, n_cinquenta, n_vinte, n_dez, n_cinco, n_um);
    
}