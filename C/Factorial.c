#include<stdio.h>
int fact(int n){
	if(n==1) return n;
	else return n*fact(n-1);
}
int main()
{
	int n;
	printf("Enter a number to find factoial: ");
	scanf("%d",&n);
	printf("The factorial of the number %d is %d",n,fact(n));
}
