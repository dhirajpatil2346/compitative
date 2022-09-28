#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--)
    {
        double n,a,b,c,d;
        cin>>n>>a>>b>>c>>d;
        if(a/c<b/d)
        {
            cout<<"PETROL"<<endl;
        }
        else if(a/c  == b/d)
        {
            cout<<"ANY"<<endl;
        }
        else
        {
            cout<<"DIESEL"<<endl;
        }
    }
    return 0;
}