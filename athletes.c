#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE_NAME 50

typedef struct athlete{
    char name[SIZE_NAME];
    int age;
    int height; //height in cm.  
} ATHLETE;

void remove_newline(char* s) {
    int n = strlen(s);
    s[n-1] = '\0';
}

ATHLETE read_athlete(){
    
    ATHLETE athlete;

    printf("Enter athlete's name:\n");
    fgets(athlete.name, SIZE_NAME, stdin);
    remove_newline(athlete.name);
    printf("Enter age:\n");
    scanf("%d", &athlete.age);
    printf("Enter height in cm:\n");
    scanf("%d", &athlete.height);

    return athlete;   
}

void print_athlete(ATHLETE athlete) {
    printf("Name: %s\n", athlete.name);
    printf("Age: %d\n", athlete.age);
    printf("Height: %d\n", athlete.height);
    printf("--------------------------------------\n");
}


int main() {
    
    FILE* fd = fopen("athletes.bin", "ab+");
    
    if(fd == NULL) {
        printf("Error opening file.\n");
    } else {
        // ATHLETE new_athlete = read_athlete();
        
        // int ret = fwrite(&new_athlete, sizeof(ATHLETE), 1, fd);
        
        // if(ret != 1) {
        //     printf("Error writing file.\n");
        // } else {
        //     printf("File successfully written.\n");
        // }

        //listar
        ATHLETE buffer;
        rewind(fd);

        while(!feof(fd)) {
            int ret = fread(&buffer, sizeof(ATHLETE), 1, fd);
            if((ret != 1) && !feof(fd)) {
                printf("Error reading file.\n");
            } else if(feof(fd)) {
                break;
            } else {
                print_athlete(buffer);
            }
        }

        printf("Name:\n");
        char name[SIZE_NAME];
        fgets(name, SIZE_NAME, stdin);
        remove_newline(name);
        
        rewind(fd);
        bool found = false;
        while(!feof(fd)) {
            int ret = fread(&buffer, sizeof(ATHLETE), 1, fd);
            if((ret != 1) && !feof(fd)) {
                printf("Error readind file.\n");
            } else if(feof(fd)) {
                break;
            } else {
                if(strcmp(name, buffer.name) == 0) {
                    found = true;
                    printf("%s's height is: %d\n", name, buffer.height);
                }
            }
        }

        if(!found) {
            printf("Athlete does not exist\n");
        }
 
            
        fclose(fd);
    }

    return 0;

}