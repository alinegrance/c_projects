#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 51

void invert_string(char str[], char inverted_str[]) {
    int n = strlen(str);

    for(int i = 0, j = n - 1; i < n, j >= 0; i++, j--) {
        inverted_str[j] = str[i];
    }

    inverted_str[n] = '\0';
}

void remove_newline(char* s) {
    s[strlen(s) - 1] = '\0';
}

int main() {

    char str[MAX];
    char tolower_str[MAX];
    char tolower_inverted_str[MAX];
    char inverted_str[MAX];
    char saida[MAX] = "sair";
    int contador = 0;
    

    do {
        printf("Entre uma string de ate 50 caracteres ou a palavra 'sair' para encerrar o programa\n");
        fgets(str, MAX, stdin); 
        remove_newline(str);

        if(strcmp(saida, str) == 0) {
            break;
        }
        
        int n = strlen(str);

        for(int i = 0; i < n; i++) {
            tolower_str[i] = tolower(str[i]);
        }
        tolower_str[n] = '\0';
        
        printf("[%s]\n", tolower_str);

        invert_string(str, inverted_str);
        invert_string(tolower_str, tolower_inverted_str);

        printf("[%s]\n", inverted_str);

        int palindromo = strcmp(tolower_str, tolower_inverted_str);

        if(palindromo == 0) {
            printf("Eh palindromo\n");
            contador++;
        } else {
            printf("Não eh palindromo\n");
        }
    
    } while(1);

    printf("Programa encerrado.\n");
    printf("Foram lidos %d palindromos.\n", contador);

}