#include <stdio.h>

int main() {

printf("\nHello round off error\n");

double a = 1.0/1.0;
double b = 1.0/2.0;
double c = 1.0/3.0;
double d = 1.0/4.0;
double e = 1.0/5.0;
double f = 1.0/6.0;

printf("\nBig to little: %G", (a+b+c+d+e+f));
printf("\nLittle to big: %G", (f+e+d+c+b+a));
printf("\nDifference: %G", (a+b+c+d+e+f) - (f+e+d+c+b+a));

 return 0;
}


