#include <stdio.h>
#include <stdlib.h>

int main() {
    int aux = 0;
    
    int* ptr = NULL;

    ptr = (int*) malloc(5 * sizeof(int));

    if(ptr == NULL) {
        printf("estoy aqui no null\n");
        exit(1);
    }
    
    printf("deu boa\n");

    for(int i = 0; i < 5; i++) {
        *(ptr+i) = aux + 10;
        aux += 10;
    }

    for(int i = 0; i<5; i++) {
        printf("%d\t", *(ptr+i));
    }
    printf("\n");

    free(ptr);

    ptr = NULL;
}