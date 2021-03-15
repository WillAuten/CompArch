/*When looking for how to time code in milliseconds in C, I found a useful post on stack overflow.
https://stackoverflow.com/questions/10192903/time-in-milliseconds-in-c
Apparently, timing things in milliseconds in C is a bit of a struggle. Also, I learned time.h and
clock() only work in seconds.
*/

#include<stdio.h>
#include <sys/time.h>

int matrixSize = 100;

int fillMatrix(int matrixToSum[][matrixSize]) {
  int counter = 1;

  for(int rowIndex = 0; rowIndex < matrixSize; rowIndex++) {
    for(int colIndex = 0; colIndex < matrixSize; colIndex++) {
      matrixToSum[rowIndex][colIndex] = counter;
      counter++;
    }
  }
}

int sumMatrixColsFirst(int matrixToSum[][matrixSize]) {
  int sum = 0;
  for(int colIndex = 0; colIndex < matrixSize; colIndex++)
  {
    for(int rowIndex = 0; rowIndex < matrixSize; rowIndex++)
    {
      sum += matrixToSum[rowIndex][colIndex];
    }
  }
  printf("Summing with columns first: %d \n", sum);

}

int sumMatrixRowsFirst(int matrixToSum[][matrixSize]) {
  int sum = 0;
  for(int rowIndex = 0; rowIndex < matrixSize; rowIndex++)
  {
    for(int colIndex = 0; colIndex < matrixSize; colIndex++)
    {
      sum += matrixToSum[rowIndex][colIndex];
    }
  }
  printf("Summing with rows first: %d \n", sum);
}

float timedifference_msec(struct timeval t0, struct timeval t1) {
  return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

int main() {
  struct timeval t0;
  struct timeval t1;
  float elapsed;

  printf("====Howdy, welcome to the matrix races!====\n\n");
  int matrixToSum[matrixSize][matrixSize];
  fillMatrix(matrixToSum);

  gettimeofday(&t0, 0);
  sumMatrixColsFirst(matrixToSum);
  gettimeofday(&t1, 0);
  elapsed = timedifference_msec(t0, t1);
  printf("Columns executed in %f milliseconds.\n\n", elapsed);

  gettimeofday(&t0, 0);
  sumMatrixRowsFirst(matrixToSum);
  gettimeofday(&t1, 0);
  elapsed = timedifference_msec(t0, t1);
  printf("Rows executed in %f milliseconds.\n\n", elapsed);

  return 0;

}
