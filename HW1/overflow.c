#include <stdio.h>

int main()
{
  printf("Overflow Demo\n");

  int a = -1;
  int b = 0;

  while(a<b)
  {
    b=b+1;
  }

  printf("\n%d\n",b);
  printf("if b is smaller than a, we had an overflow...\n");

  return 0;
}
