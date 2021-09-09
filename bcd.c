#include <stdio.h>
#include <string.h>
 
int Bin2Dec(char bin[],int pos,int exp)
{
  if(pos<0) {
    return 0;
  }
  return (bin[pos]-48)*exp + Bin2Dec(bin,pos-1,exp*2);
}
 
int main()
{
  char binario[9]="10011101";  //valor em decimal = 157
  printf("Valor convertido: %d\n", Bin2Dec(binario,strlen(binario)-1,1));
  return 0;
}