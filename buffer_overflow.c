#include <stdio.h>
#include <string.h>

int main(){

    char str0[6] = "98765", str1[5] = "abcd", str2[10] = "efghijklm";

    printf("str0 = %s\n str1 = %s\n str2[10] = %s\n", str0, str1, str2);
    strcpy(str1, "1234567");

    printf("str0 = %s\n str2 = %s\n", str0, str2);

    return 0;
}