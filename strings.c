#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char name[20];
    char otherName[20] = "Johann";
    int lenght;

    printf("Enter your name:\n");
    fgets(name, 20, stdin);

    lenght = strlen(name);
    printf("lenght: %d\n", lenght);

    return 0;
}