#include <stdio.h>


void swap_two_numbers(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}



int main() {
    int x = 10;
    int y = 20;

    swap_two_numbers(&x, &y);

    printf("x: %d, y: %d\n", x, y);
}


// int main(int argc, char** argv) {
//     printf("Number of arguments: %d\n", argc);

//     for (int i = 0; i < argc; i++) {
//         printf("arg%d: %s\n", i, argv[i]);
//     }
// }
