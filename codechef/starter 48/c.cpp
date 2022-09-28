#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n,k,x,y;
        cin>>n>>k>>x>>y;
        if(x<=y)
        {
        int red =max(n,k);
        int blue=n-red;
        cout<<red*x+blue*y<<endl;
        }
        else
        {
            int red =k;
        int blue=n-red;
        cout<<red*x+blue*y<<endl;
        }
    }
    return 0;
}