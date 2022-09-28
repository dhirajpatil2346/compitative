#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        double a,b,x,y;
        cin>>a>>b>>x>>y;
        if(a/x<b/y)
        {
            cout<<"Bob"<<endl;
        }
        else if(a/x>b/y)
        {
            cout<<"Alice"<<endl;
        }
        else
        {
            cout<<"EQUAL"<<endl;
        }
    }
    return 0;
}