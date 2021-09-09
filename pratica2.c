#include <stdio.h>
#include <math.h> //compilar com -lm 


//calcula i:

// int main() {
//     double v = 10.00;
//     double r = 100.00;

//     double i = v/r;

//     printf("i: %.2lf\n", i);

// }

//calcula polinomio de taylor:

int fat(int n)
{
  return (n == 1 || n == 0) ? 1 : fat(n - 1) * n;
}

int main() { 
    double x_grau = 80;   //em graus
    double x = (80*M_PI)/180; 

    double cos_x_taylor = 1 - (pow(x, 2)/fat(2)) + (pow(x, 4)/fat(4)) - (pow(x, 6)/fat(6)) + (pow(x, 8)/fat(8));
    double cos_x_real = 0.173648;
    

    printf("aproximação de taylor para cos(%.3lf): %.6lf\n", x, cos_x_taylor);
    printf("valor exato de cos(%.3lf): %.6lf\n", x, cos_x_real);
    printf("diferença entre exato e aproximado: %.6lf\n", (cos_x_real - cos_x_taylor));

    return 0;
}



