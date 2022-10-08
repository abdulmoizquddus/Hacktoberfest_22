#include <bits/stdc++.h>
using namespace std;
int main()
{int t;
cin>>t;
while(t>0)
{
  int n,k,a[1000000],b[1000000],i,j,p=0;
  cin>>n>>k;
  for(i=0;i<n;i++)
  { cin>>a[i];}
  for(i=0;i<n;i++)
  {
    b[(i+k)%n]=a[i];
  }
  for(i=0;i<n;i++)
  {
    a[i]=b[i];
  }
  
  for(i=0;i<n;i++)
  {
    cout<<a[i]<<" ";
  }cout<<"\n";
  t--;
}
  return 0;
}
