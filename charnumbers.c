#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGIT 3
#define MAX_NUM 100

void parse_line(FILE* file, int vector[]) {
    char line[MAX_DIGIT * MAX_NUM + MAX_NUM +1];
    char* buffer;
    int i = 0;
    
    fgets(line, (MAX_DIGIT * MAX_NUM + MAX_NUM) + 1, file);

    buffer = strtok(line, "*");

    if(buffer != NULL) {
        vector[i] = atoi(buffer);
        i++;

        while((buffer = strtok(NULL, "*")) != NULL) {            
            vector[i] = atoi(buffer);
            i++;
        }
    }
    vector[i] = -1;
}

int main() {
    FILE* file;
    int vector[MAX_NUM];
    int i = 0;

    if(!(file = fopen("numbers.txt", "r+"))) {
        printf("Error opening file.\n");
        return -1;
    } else {
        parse_line(file, vector);
        fclose(file);

        printf("Int vector:\n");
        while(vector[i] != -1) {
            printf("%d\t", vector[i]);
            i++;
        }
        printf("\n");
    }
    return 0;
}