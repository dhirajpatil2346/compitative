#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        while(n%2==0){n/=2;}
        while(k%2==0){k/=2;}
        if(n==k){cout<<"YES"<<endl;}
        else{cout<<"NO"<<endl;}
    }
    return 0;
}