 #include <stdio.h>

 void decimal_to_binary(int n){
     if(n == 0) {
         printf("%d", n);
     } else {
         decimal_to_binary(n/2);
         printf("%d", n%2);
     }
 }

 int main() {

     int x = 11;

     decimal_to_binary(x);

     return 0;
 }