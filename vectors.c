#include <stdio.h>

int main(){

    float scores[8], average = 0;
    int i;

    for(i = 0; i < 8; i++){
        printf("%dº Score\n", i+1);
        scanf("%f", &scores[i]);
    }

    for(i = 0; i < 8; i++){
        average = average + scores[i];
        // or average += scores[i]
    }

    average = average / 8;
    printf("Average scores is: %.2f\n", average);

    return 0;
}