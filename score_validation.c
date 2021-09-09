#include <stdio.h>

int main(){
    float score1, score2, averagescore;

    printf("Enter score1: ");
    scanf("%f", &score1);
    printf("Enter score2: ");
    scanf("%f", &score2);

    averagescore = (score1 + score2) / 2;

    if(averagescore >= 6){
        printf("Your average score is %.2f\n", averagescore);
        printf("approved!\n");
    } 
    else{
        printf("Your average score is %.2f\n", averagescore);
        printf("not approved\n");
    }

    return 0;
}