#include <stdio.h>

int main(){

    int n, fat=1, i=1;
    printf("Enter number: \n");
    scanf("%d", &n);
    

    //if/else/for version

    // if(n<0){
    //     printf("negative numbers no can do.\n");
    // }
    // else{
    //     if(n==0){
    //         fat=0;
    //     }
    //     else{
    //         for(i; i<=n; i++){
    //             fat = fat * i;
    //         }
    //     }
    //     printf("%d factorial = %d\n", n, fat);
    // }

    //if/else/do/while version
    
    // if(n<0){
    //     printf("negative number no can do.\n");
    // }
    // else{
    //     if(n==0){
    //         fat=1;
    //     }
    //     else{
    //         do{
    //             fat = fat * i;
    //             i++;
    //         }
    //         while(i <= n);
    //     }
    //     printf("%d factorial = %d\n", n, fat);
    // }

    //if/else/while version

    if(n<0){
        prinf("negative number no acn do.\n");
    }
    else{
        i = n;
        while(i!=0){
            fat = fat * i;
            i--;
        }
        printf("%d factorial = %d\n", n, fat);
    }

    return 0;

}