#include<iostream>
using namespace std;
int main(){
    int s;
    cout<<"size";
    cin>>s;
    int a[s];
    for(int i=0;i<s;i++){
        cin>>a[s];
    }
    for(int i=0;i<s;i++){
        int c=0;
        for(int j=0;j<s;j++){
            if(a[i]==a[j]){
                c=c+1;
                a[i]=c;
            }
        }
    }
    for(int i=0;i<s;i++){
        if(a[i]==2){
            return a[i];
        }
    }
    return 0;
}