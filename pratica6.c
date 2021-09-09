#include <stdio.h>
#include <stdbool.h>

#define MAX_NUM 10


void bubble_sort(int a[], int n) {
    int aux;
    bool swap;
    int i;
    do {
        swap = false;
        for(i = 1; i <= n-1; i++) {
            if(a[i-1] > a[i]) {
                aux = a[i];
                a[i] = a[i-1];
                a[i-1] = aux;
                swap = true;
            }
        }
    } while (swap);
      
}

int main() {
    int array[MAX_NUM] = {3, 5, 12, 1, 9, 15, 10, 11, 4, 2};
    int i;

    printf("array desordenado:\n");
    for(i = 0; i < MAX_NUM; i++) {
        printf("%d\t", array[i]);
    }

    printf("\n----------------------------------------------------------------------------- \n");
    
    bubble_sort(array, MAX_NUM);

    printf("array ordenado:\n");
    for(i = 0; i < MAX_NUM; i++) {
        printf("%d\t", array[i]);
    }

    printf("\n");

}