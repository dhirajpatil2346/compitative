#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int up = n-1,right=m-1;
        int l=0,r=0;
        if(up%2)
        {
            l=1;
        }
        else{
            l=2;
        }
        if(right%2)
        {
            r=1;
        }
        else{
            r=2;
        }
        int total = l + r;
        if(total%2)
        {
            cout<<"Burenka"<<endl;
        }
        else{
            cout<<"Tonya"<<endl;
        }
    }
    return 0;
}