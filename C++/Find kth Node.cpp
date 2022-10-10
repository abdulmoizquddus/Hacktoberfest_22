Node*deletNode(Node* start, int k)
{
if(k<1)
return start;

if(start==NULL)
{
return NULL;
}

if(k==1)
{
Node*res=start->next;
delete(start);
return res;
}

start->next=deleteNode(start->next, k-1);
return start;

// how to find sum

#include <iostream>
using namespace std;

int addNum(int n);

int main() {
    int n;

    cout << "Enter Number: ";
    cin >> n;

    cout << "Sum =  " << addNum(n);

    return 0;
}

int add(int n) {
    if(n != 0)
        return n + addNum(n - 1);
    return 0;
}