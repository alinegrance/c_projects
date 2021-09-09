#include <stdio.h>
#include <string.h>

#define SIZE_NAME 10
#define CPF 12

typedef struct person {
    char name[SIZE_NAME];
    char cpf[CPF];
    int age;
} PERSON;

int insert_person(char name[], char cpf[], int age, FILE* file) {
    PERSON person;
    strcpy(person.name, name);
    strcpy(person.cpf, cpf);
    person.age = age;
    if(fwrite(&person, sizeof(PERSON), 1, file) != 1) {
        return -1;
    }
    return 0;
}

int find_person(char cpf[], PERSON* person, FILE* file) {
    int position;
    rewind(file);
    while(1) {
        position = ftell(file);
        fread(person, sizeof(PERSON), 1, file);
        if(feof(file)) {
            break;
        }
        if(!strcmp(person->cpf, cpf)) {
            return position;
        }
    }
    return -1;
}

int main() {
    FILE* people;
    PERSON person;
    int position;
    char cpf[CPF];
    int result;

    people = fopen("list_of_people.bin", "wb+");
    if(people == NULL) {
        printf("Error.\n");
        return 0;
    }

    if(insert_person("person1", "12345678901", 20, people) == -1) {
        printf("Error.\n");
        return -1;
    }

    if(insert_person("person2", "12345678902", 25, people) == -1) {
        printf("Error.\n");
        return -1;
    }
    
    if(insert_person("person3", "12345678903", 30, people) == -1) {
        printf("Error.\n");
        return -1;
    }

    printf("Enter cpf: \n");
    scanf("%s", cpf);
    printf("[%s]\n", cpf);
    position = find_person(cpf, &person, people);

    if(position == -1) {
        printf("Not found.\n");

    } else {
        printf("Person found:\nposition: %d\tname: %s\tcpf: %s\tage: %d\n", position, person.name, person.cpf, person.age);
    }

    fclose(people);
    return 0;
}