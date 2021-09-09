#include <stdio.h>

int funcao(int a, int *b)
  {
     a++;
     *b = a * 2;
     return b+5;
  }
 
int main()
{
   int x=4,y=8,z;
   z = funcao(x,&y);
   printf("%d  %d  %d" ,x,y,z);
   return 0;
}