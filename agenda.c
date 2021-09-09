#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    FILE* file;
    char name[51], find_name[51];
    int prefix, phone_number, option;
    bool not_found = true;

    if(!(file = fopen("agenda.txt", "a+"))) {
        printf("error opening file.\n");
        return -1;
    // } else {
    //     do{
    //         printf("Enter name: ");
    //         fgets(name, 50, stdin);
    //         name[strlen(name)-1] = '\0';        //you have to tell where is EOF.
    //         printf("Enter prefix: ");
    //         scanf("%d", &prefix);
    //         printf("Enter phone number: ");
    //         scanf("%d", & phone_number);

    //         fprintf(file, "%s %d %d\n", name, prefix, phone_number);    // now that you have all on buffer, you just have to write it on the file.

    //         printf("Do you wish to keep adding? 1-Yes - 2-No\n");
    //         scanf("%d", &option);
    //         getchar();

    //     } while(option != 2);
    }

    rewind(file);

    printf("Enter name you wish to find: ");
    fgets(find_name, 50, stdin);
    find_name[strlen(find_name)-1] = '\0';

    while(!feof(file) && not_found == true) {
        fscanf(file, "%s %d %d", name, &prefix, &phone_number);
        //printf("[%s: (%d) %d]\n", name, prefix, phone_number);      // test print.
        if(strcmp(name, find_name) == 0) {
            printf("%s: (%d) %d\n", name, prefix, phone_number);
            not_found = false;
        }
    }
    if(not_found) {
        printf("Entry does not exist.\n");
    }

    fclose(file);

}