/*
  Program to read in two numbers and multiply them

  Input: num1, an integer
         num2, a float

  Output: result, a float
*/

#include <stdio.h>

int main(void)
{

  /* declare some variables */
  int num1;
  float num2;
  float result;

  /* input values into variables */
  printf("Please input an integer\n");
  scanf("%d", &num1);
  printf("Please input a floating point number\n");
  scanf("%f", &num2);

  /* do a computation */
  result = num1 * num2;

  /* Output the result of the computation */
  printf("%d multiplied by %f = %f\n", num1, num2, result);

  return 0;

}
