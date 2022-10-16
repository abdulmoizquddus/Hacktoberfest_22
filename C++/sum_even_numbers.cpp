#include<iostream>
using namespace std;
int SumEven(int num1, int num2)
{
    if(num1>num2)
    return 0;
return num1+SumEven(num1+2,num2);
}
int main()
{
    int num1=2,num2;
    cout<<"Enter your Limit:";
    cin>>num2;
    cout<<"Sum of all Even numbers in the given range is:"<<SumEven(num1,num2);
}
