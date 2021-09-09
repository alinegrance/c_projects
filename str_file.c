#include <stdio.h>
#include <string.h>

int main() {
  
    FILE* file;
    int value;
    int list[5];

    if(!(file = fopen("int_list.txt", "w+"))) {
        printf("error.\n");
    } else {
        printf("Enter 5 ints: \n");
        for( int i = 0; i < 5; i++) {
            scanf("%d", &value);
            fprintf(file, "%d\n", value);
        }
    }

    rewind(file);

    for(int i = 0; i < 5; i++) {
        fscanf(file, "%d\n", &list[i]);
        printf("list[%d] = %d\n", i, list[i]);
    }

    fclose(file);
    return 0;
}
