#include <stdio.h>

int max(int vs[], int i, int n) {
    if(n == 0) {
        return 0;
    }
    if(i == (n-1)) {
        return vs[i];
    }
    int max_aux = max(vs, i+1, n);

    return vs[i] >= max_aux ? vs[i] : max_aux;
}

int main() {

    int array[3] = {-3, -1, 0};

    printf("%d\n", max(array, 0, 3));

}