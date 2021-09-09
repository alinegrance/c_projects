#include <stdio.h>
#include <string.h>

int main() {
    
    FILE* file;
    char old, new, cursor;
    int replaced_char = 0;

    file = fopen("texto_original.txt", "r+");
    if(file == NULL) {
        printf("error.\n");
        return -1;
    } else {
        //printf("Success.\n");
        printf("char to be replaced: ");
        scanf(" %c", &old);
        printf("Char to put instead: ");
        scanf(" %c", &new);

        while(!feof(file)) {
            cursor = getc(file);
            if(cursor == old) {
                replaced_char++;
                fseek(file, -1 * sizeof(char), SEEK_CUR);
                putc(new, file);
                fflush(file);
            }
        }
        fclose(file);
        printf("Number of replaced characters: %d", replaced_char);
    }

    return 0;
}