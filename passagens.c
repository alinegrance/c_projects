#include <stdio.h>
#include <string.h>

#define MAX 50
#define MAX_ASS 5
#define MAX_STRUCT 200

typedef struct data {
    int dia, mes, ano;
} DATA;

typedef struct horario {
    int hora, min;
} HORARIO;

typedef struct passagem {
    int cod_empresa;
    char nome_passageiro[MAX];
    char origem[MAX];
    char destino[MAX];
    char assento[MAX_ASS];
    double valor;
    DATA data;
    HORARIO horario;
} PASSAGEM; 

void remove_newline(char* s) {
    s[strlen(s) - 1] = '\0';
}

void ler_bilhete(PASSAGEM* passagem) {
    printf("Codigo da empresa:\n");
    scanf("%d", &(passagem->cod_empresa));
    printf("Data: (dia mes ano)\n");
    scanf("%d %d %d", &(passagem->data.dia),  &(passagem->data.mes), &(passagem->data.ano));
    printf("Horario: (hora minutos)\n");
    scanf("%d %d*c", &(passagem->horario.hora), &(passagem->horario.min));
    printf("Valor:\n");
    scanf("%lf*c", &(passagem->valor));
    printf("Nome do passageiro:\n");
    getchar();
    fflush(stdin);
    fgets(passagem->nome_passageiro, MAX, stdin);
    remove_newline(passagem->nome_passageiro);
    fflush(stdin);
    printf("Origem:\n");
    fflush(stdin);
    fgets(passagem->origem, MAX, stdin);
    remove_newline(passagem->origem);
    fflush(stdin);
    printf("Destino:\n");
    fflush(stdin);
    fgets(passagem->destino, MAX, stdin);
    remove_newline(passagem->destino);
    fflush(stdin);
    printf("Assento: (numero letra)\n");
    fflush(stdin);
    fgets(passagem->assento, MAX_ASS, stdin);
    remove_newline(passagem->assento);
    
}

void mostrar_bilhete(PASSAGEM passagem) {
    printf("*******************************************\n");
    printf("\n");
    printf("Codigo da empresa: %d\n", passagem.cod_empresa);
    printf("Data: %d/%d/%d\n", passagem.data.dia, passagem.data.mes, passagem.data.ano);
    printf("Horario: %d:%d hrs\n", passagem.horario.hora, passagem.horario.min);
    printf("Nome do passageiro: %s\n", passagem.nome_passageiro);
    printf("Origem: %s\n", passagem.origem);
    printf("Destino: %s\n", passagem.destino);
    printf("Assento: %s\n", passagem.assento);
    printf("Valor: R$ %.2f\n", passagem.valor);
    printf("\n");
}

void passagens_ao_mes(PASSAGEM* passagens, int qtd_passagens, int mes) {
    int i, contador = 0;
    printf("Vendas do mes: %d\n", mes);
    for(i = 0; i < qtd_passagens; i++) {
        if(passagens[i].data.mes == mes) {
            contador++;
        }
    }
    printf("Total: %d\n", contador);
}

int main() {
    PASSAGEM passagens[MAX_STRUCT];
    int i, n;

    do {
        printf("Qual o numero de passagens a ser processado?\n");
        scanf("%d", &n);
        
        if(n < 0 || n > 200) {
            printf("valor invalido.");

        }
    } while (n < 0 || n > 200);

    for(i=0; i<n; i++) {
        ler_bilhete(&passagens[i]);
        printf("\n");
    }

    for(i=0; i<n; i++) {
        mostrar_bilhete(passagens[i]);
    }

    printf("*******************************************\n");

    passagens_ao_mes(passagens, n, 12);
    return 0;

}