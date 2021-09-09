#include <stdio.h>

double resistor_paralelo(double a, double b) {
    return (a * b) / (a + b);
}

double capacitor_paralelo(double a, double b) {
    return (a + b);
}


int main() {
    
    double valor1;
    double valor2;
    char componente;

    do {
        printf("Digite 'c' para capacitores ou 'r' para resistores\n");
        scanf(" %c", &componente);
    } while ((componente != 'c') && (componente != 'r'));

    switch(componente) {
        
        case 'c':
            do {
                printf("Insira o primeiro valor\n");
                scanf(" %lf", &valor1);
            } while (valor1 <= 0);
            
            do {
                printf("Insira o segundo valor\n");
                scanf(" %lf", &valor2);
            } while (valor2 <= 0);        

            printf("Cequiv: %.2lf\n", capacitor_paralelo(valor1, valor2));
            break;

        case 'r':
            do {
                printf("Insira o primeiro valor\n");
                scanf(" %lf", &valor1);
            } while (valor1 <= 0);
            
            do {
                printf("Insira o segundo valor\n");
                scanf(" %lf", &valor2);
            } while (valor1 <= 0);

            printf("Requiv: %.2lf\n", resistor_paralelo(valor1, valor2));
            break;
    }

    return 0;
}