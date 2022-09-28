#include<bits/stdc++.h>
using namespace std;

int main(){
    int k,n,w;
    cin>>k>>n>>w;
    // cout<<"k is "<<k<<endl;
    int t=0;
    for (int i = 0, j=0; i < w;++i)
    {
        // cout<<i<<"  "<<t<<endl;
        j=j+k;
        t+=j;
    // cout<<t<<"  "<<endl;
    }
    if(t<n){
        cout<<"0";
    }
    else{
    cout<<t-n;
    }
    return 0;
}