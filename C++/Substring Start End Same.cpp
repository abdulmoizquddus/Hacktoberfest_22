#include <bits/stdc++.h>
using namespace std;
int substringSES(string s,int start,int end){
  if(end == s.size()){
    start++;
    end = start;
  }
  if(end == s.size())
    return 0;
  if(s[start] == s[end])
    return 1 + substringSES(s, start, end + 1);
  else 
    return substringSES(s, start, end + 1); 
}
int main()
{
  int t;cin>>t;
  while(t--){
    string s;cin>>s;
    int start = 0;
    int end = s.size()-1;
    cout<<substringSES(s,start,start)<<"\n";
  }
  return 0;
}
