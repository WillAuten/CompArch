#include <stdio.h>
#include <math.h>

int sumRunner(int sumNumber, int limitNumber) {
  for(int index = 1; index <= limitNumber; index++ ){
    sumNumber += index;
  }
  return printf("Sum from 1 to %i is %i\n", limitNumber, sumNumber);
}

int main() {
  printf("Hello sum printing\n");
  int sumTen;
  int sumOneHundred;
  int sumOneThousand;
  int sumTenThousand;

  printf("\n");
  sumTen = sumRunner(0, 10);

  printf("\n");
  sumOneHundred = sumRunner(0, 100);

  printf("\n");
  sumOneThousand = sumRunner(0, 1000);

  printf("\n");
  sumTenThousand = sumRunner(0, 10000);

  return 0;
}
