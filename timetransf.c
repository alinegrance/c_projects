#include <stdio.h>
#include <math.h>

int main() {
    int segundos, seg, min, hrs;
    printf("Entre um tempo em segundos:\n");
    scanf("%d", &segundos);

    hrs = segundos/3600;
    min = (segundos%3600)/60;
    seg = (segundos%3600)%60;
    
    printf("%02dhrs %02dmin e %02dseg\n", hrs, min, seg);
}