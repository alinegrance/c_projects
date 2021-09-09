#include <stdio.h>

// "*" -> E
// "+" -> OR

int main() {
    char op1;
    int bit1;
    int bit2;
    char op2;
    int bit3;
    int aux;
    int result;

    do {
        printf("insira primeiro operador:");
        scanf(" %c", &op1);
    }
    while((op1 != '*') && (op1 != '+'));
    printf("op1: %c\n", op1);

    do {
        printf("insira primeiro bit:");
        scanf("%d", &bit1);
    }
    while((bit1 != 0) && (bit1 != 1));
    printf("bit1: %d\n", bit1);

    do {
        printf("insira segundo operador:");
        scanf(" %c", &op2);
    }
    while((op2 != '*') && (op2 != '+'));
    printf("op2: %c\n", op2);

    do {
        printf("insira segundo bit:");
        scanf("%d", &bit2);
    }
    while((bit2 != 0) && (bit2 != 1));
    printf("bit2: %d\n", bit2);

    do {
        printf("insira terceiro bit:");
        scanf("%d", &bit3);
    }
    while((bit3 != 0) && (bit3 != 1));
    printf("bit3: %d\n", bit3);


    if(op2 == '+') {
        if((bit2 == 0) && (bit3 == 0)) {
            aux = 0;
        } else {
            aux = 1;
        }
    }

    if(op2 == '*') {
        if((bit2 == 1) && (bit3 == 1)) {
            aux = 1;
        } else {
            aux = 0;
        }
    }

    if(op1 == '+') {
        if(aux == 0 && bit1 == 0) {
            result = 0;
        } else {
            result = 1;
        }
    }

    if(op1 == '*') {
        if(aux == 1 && bit1 == 1) {
            result = 1;
        } else {
            result = 0;
        }
    }

    printf("Entradas ==> %c, %d, %c, %d, %d\n", op1, bit1, op2, bit2, bit3);
    printf("Saida ==> %d\n", result);

    return 0;
}