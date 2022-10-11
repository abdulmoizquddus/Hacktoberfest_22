#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    vector<int> v;
    stack<pair<int,int> > s;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        if(s.empty())
        {
            v.push_back(-1);
        }
        else if(s.empty()==false && s.top().first>a[i])
        {
            v.push_back(s.top().second);
        }
        else if(s.empty()==false && s.top().first<=a[i])
        {
            while( s.empty()==false && s.top().first<=a[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                v.push_back(-1);
            }
            else{
                v.push_back(s.top().second);
            }
        }
        s.push(make_pair(a[i],i));
    }
    for(int i=0;i<v.size();i++)
    {
        v[i]=i-v[i];
    }
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}
