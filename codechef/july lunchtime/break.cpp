#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        int b=0;
        if(x%3)
        {
            b=x/3;
        }
        else
        {
            b=x/3-1;
        }
        b=max(0,b);
        cout<<x*y+b*z<<endl;
     
    }
    return 0;
}