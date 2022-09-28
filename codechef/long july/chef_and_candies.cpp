#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int r = n-x;
        if(r<=0)
        {
            cout<<0<<endl;
        }

        else if(r%4)
        {
            cout<<r/4+1<<endl;
        }
        else
        {
            cout<<r/4<<endl;
        }
    }
    return 0;
}