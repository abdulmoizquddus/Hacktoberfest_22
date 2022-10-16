#include <stdio.h>
int SumEven(int num1, int num2)
{
    if (num1 > num2)
        return 0;
    return num1 + SumEven(num1 + 2, num2);
}
int main()
{
    int num1 = 2, num2;
    printf("Enter your Limit:");
    scanf("%d", &num2);
    printf("Sum of all Even numbers in the given range is: %d", SumEven(num1, num2));
}