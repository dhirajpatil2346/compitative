#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int a,b;
        cin>>a>>b;
        if(a % b != 0)
            cout<<((a/b + 1) * b - a)<<endl;
        else 
            cout<<0<<endl;
    }
    
    return 0;
}