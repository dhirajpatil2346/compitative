#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int f=0;
    for (int i = 0, r=0; i < n; i++)
    {
        int v,t;
        cin>>v>>t;
        if((t-v)>1){
            r++;
        }
        f=r;
    }
    cout<<f;
    return 0;
}