//Trabalho unidade 1 - Aline Grance de Oliveira

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define MAX_STR 50
#define MAX_PLATE 10
#define MAX_VEHICLES 10

#define OPTION_EXIT 6

const char* SEP = "------------------------------------------------------------------";

typedef struct vehicle {
    char brand[MAX_STR]; 
    char model[MAX_STR];
    int year;
    char plate[MAX_PLATE];
} VEHICLE;

void print_sep() {
    printf("%s\n", SEP);
}

void print_vehicle(VEHICLE* v) {
    printf("*************************************************\n");
    printf("marca: %s\n", v->brand);
    printf("modelo: %s\n", v->model);
    printf("ano: %d\n", v->year);
    printf("placa: %s\n", v->plate);
}

void print_vehicles(VEHICLE v[], int* n) {
    for(int i=0; i<*n; i++) {
        print_vehicle(&v[i]);
        printf("\n");
    }
}

void print_vehicles_by_year(VEHICLE v[], int* n, int year) {
    for(int i=0; i<*n; i++) {
        if(v[i].year == year) {
            print_vehicle(&v[i]);
            printf("\n");
        }
    }
}

void print_vehicles_since_year(VEHICLE v[], int* n, int year) {
    for(int i=0; i<*n; i++) {
        if(v[i].year >= year) {
            print_vehicle(&v[i]);
            printf("\n");
        }
    }
}

void print_vehicles_by_model(VEHICLE v[], int* n, char model[]) {
    for(int i=0; i<*n; i++) {
        if(strcmp(v[i].model, model) == 0) {
            print_vehicle(&v[i]);
            printf("\n");
        }
    }

}

void insert_vehicle(VEHICLE vs[], int* n, VEHICLE v) {
    if (*n < MAX_VEHICLES) {
        if(*n == 0) {
            vs[0] = v;
        }
        else {
            int i = 0;

            while ((vs[i].year <= v.year) && (i < *n)) {
                i++;
            }
            
            VEHICLE aux1, aux2;
            
            aux1 = v;
            
            for(int j=i; j<=*n; j++) {
                aux2 = vs[j];
                vs[j] = aux1;
                aux1 = aux2;
            }
        }
    }
}

void remove_newline(char* s) {
    s[strlen(s) - 1] = '\0';
}

void read_string(char str[], int size) {
    fgets(str, size, stdin);
    remove_newline(str);
}

void flush_in() {
    fflush(stdin);
}

void insert_vehicle_from_stdin(VEHICLE* vehicles, int* n) {
    VEHICLE v;
    regex_t regex;
    int reti;
    char strbuf[MAX_PLATE];

    reti = regcomp(&regex, "[A-Z]{3}-[0-9]{4}", REG_EXTENDED);
    if (reti) {
        fprintf(stderr, "Could not compile regex\n");
        exit(1);
    }

    //testa o padraõ de placa entrado pelo usuario 
    do {
        printf("insira a placa do carro no modelo [XXX-0000]:");
        read_string(strbuf, MAX_PLATE);
        flush_in();
        reti = regexec(&regex, strbuf, 0, NULL, 0);
    } while (reti == REG_NOMATCH);

    strcpy(v.plate, strbuf);
    regfree(&regex);

    printf("insira a marca do carro:");
    read_string(v.brand, MAX_STR);
    flush_in();

    printf("insira o modelo do carro:");
    read_string(v.model, MAX_STR);
    flush_in();

    do {
        printf("insira o ano de fabricacao:");
        scanf("%d%*c", &v.year);
        flush_in();
    } while ((v.year < 0) || (v.year > 2021)); // teste para ano entre 0 e 2021

    insert_vehicle(vehicles, n, v);
}

void display_options() {
    printf("Bem Vindo a sua lista de carros, entre o número da operação que deseja realizar:\n");
    printf("1-listar veiculos\n");
    printf("2-inserir um veiculo novo\n");
    printf("3-listar veiculos por ano\n");
    printf("4-listar veiculos a partir de um certo ano\n");
    printf("5-listar veiculos por modelo\n");
    printf("6-sair do programa\n");
}

int read_option() {
    int option;
    scanf("%d", &option);
    getchar();

    return option;              
}

void display_by_year(VEHICLE* vehicles, int* n) {
    int year;

    printf("Entre o ano desejado: ");
    scanf("%d", &year);
    print_vehicles_by_year(vehicles, n, year);
}

void display_since_year(VEHICLE* vehicles, int* n) {
    int year;
    printf("Entre o ano desejado: ");
    scanf("%d", &year);
    print_vehicles_since_year(vehicles, n, year);
}

void display_by_model(VEHICLE* vehicles, int* n) {
    printf("Digite o nome do modelo que deseja listar:");
    char model[MAX_STR];
    read_string(model, MAX_STR);
    print_vehicles_by_model(vehicles, n, model);
}



int main() {
    
    VEHICLE vehicles[MAX_VEHICLES];

    //Exemplos de veiculos:

    // strncpy(vehicles[0].brand, "renault", MAX_STR);
    // strncpy(vehicles[0].model, "1", MAX_STR);
    // vehicles[0].year = 1890;
    // strncpy(vehicles[0].plate, "ABC-1234", MAX_PLATE);
    
    // strncpy(vehicles[1].brand, "fiat", MAX_STR);
    // strncpy(vehicles[1].model, "2", MAX_STR);
    // vehicles[1].year = 2010;
    // strncpy(vehicles[1].plate, "FLG-4321", MAX_PLATE);

    // strncpy(vehicles[2].brand, "pato", MAX_STR);
    // strncpy(vehicles[2].model, "3", MAX_STR);
    // vehicles[2].year = 2019;
    // strncpy(vehicles[2].plate, "KZK-8765", MAX_PLATE);

    int option;
    int n = 0;

    do{
        display_options();
        option = read_option();

        switch(option) {
            case 1:
                print_sep();
                print_vehicles(vehicles, &n);
                print_sep();
                break;
            case 2:
                print_sep();
                insert_vehicle_from_stdin(vehicles, &n);
                n++;
                print_sep();
                break;
            case 3:
                print_sep();
                display_by_year(vehicles, &n);
                print_sep();
                break;
            case 4:
                print_sep();
                display_since_year(vehicles, &n);
                print_sep();
                break;
            case 5:
                print_sep();
                display_by_model(vehicles, &n);
                print_sep();
                break;
            case 6:
                print_sep();
                printf("Você finalizou o programa\n");
                print_sep();
                break;
            default:
                printf("opção invalida\n\n\n");
        }

    } while(option != OPTION_EXIT);

    return 0;
}