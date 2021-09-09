#include <stdio.h>
#include <string.h>

int main() {


    // int a = 10;
    // char b = 'b';

    // printf("%d\n", a + b);

    // char ch;
    // int i = 321;
    // ch = i;

    // printf("%c\t %d\t %x\n", ch, ch, ch);

    char string[1000];
    int lenght;

    strcpy(string, "pudim");
    printf("%s\n", string);
    lenght = strlen(string);

    int i, j;
    char aux;

    //this for inverts the string characters
    for(i = 0, j = lenght -1; i < j; i++, j--) {
        aux = string[i];
        string[i] = string[j];
        string[j] = aux;
    }

    printf("%s\n", string);

    return 0;
}