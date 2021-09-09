#include <stdio.h>
#include <string.h>
#define MAX_SIZE 300
#define N 1

int main() {

    char string[MAX_SIZE] = "EU AMO TANTO ESSA CANZA COTOCA QUE EU AMO EM CAPS";
    char cripto_string[MAX_SIZE];

    for(int i = 0; i < MAX_SIZE; i++) {

        if((string[i] >= 65) && (string[i] <= 90-N)) {
            cripto_string[i] = (char)((int)string[i]+N);

        } else if((string[i] >= (90-N+1)) && (string[i] <= 90)) {
            cripto_string[i] = (char)(65 + ((int)string[i]+N)%91);
            
        } else if((string[i] >= 97) && (string[i] <= 122-N)) {
            cripto_string[i] = (char)((int)string[i]+N);

        } else if((string[i] >= 122-N+1) && (string[i] <= 122)) {
            cripto_string[i] = (char)(97 + ((int)string[i]+N)%123);

        } else {
            cripto_string[i] = string[i];
        }
    }
    
    printf("%s\n", string);
    printf("%s\n", cripto_string);


}


