#include<stdio.h>
int sum(int number)
{
    int i=1;
    if(number>0)
    {
        return number + sum(number-1);
    }
    else
    {
        return 0;
    }
}
int main()
{
    int size;
    printf("Enter the size of number\n");
    scanf("%d",&size);
    printf("Sum :%d",sum(size));
    }