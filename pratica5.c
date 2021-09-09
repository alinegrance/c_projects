#include <stdio.h>

int main() {
    int codigo;
    int habitantes;
    int soma = 0;
    int municipios = 0;
    int vilarejos = 0;

    do {

        printf("Digite o codigo do municipio:\n");
        scanf("%d", &codigo);

        if(codigo == 0) {
            break;
        }
        
        do {
            printf("Digite o numero de habitantes:\n");
            scanf("%d", &habitantes);
        } while (habitantes <= 0);
        
        if(habitantes < 1000) {
            vilarejos++;
            printf("Municipio %d eh um vilarejo\n", codigo);        
        }

        municipios++;
        soma += habitantes;
        
    } while (codigo != 0);

    printf("------------------------------------------------\n");
    printf("Programa encerrado.\n");
    printf("------------------------------------------------\n");
    printf("Total de municipios lidos: %d\n", municipios);
    printf("População media: %.3lf\n", ((double) soma)/municipios );
    printf("Numero de vilarejos: %d\n", vilarejos);
    printf("-----------------------------------------------\n");
    

    return 0;
}