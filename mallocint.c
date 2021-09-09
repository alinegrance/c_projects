#include <stdio.h>
#include <stdlib.h>

void add_int(int* ptr, int n, int a) {
    ptr[0] = a;
    // int i;
    // for(i = 0; i < n; i++) {
    //     if(ptr[i] = )  {
    //     ///como testar se tem coisa alocada aqui .... T_T
    //     //do nothing and skip to the next :B
    //     } else{
    //         ptr[i] = a;
    //         break; //is that the right place o_o ? 
    //     }
        
    // } 

}

int main() {

    int* ptr = (int*)malloc(10*sizeof(int));
    if(ptr == NULL) {
        printf("fail allocating memory.\n");
    } else {

    }


}