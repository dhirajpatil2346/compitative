#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    if(n==1)
    {
        cout<<m-1<<endl;
    }
    else if(m==1)
    {
        cout<<n-1<<endl;
    }
    else
    {
        long long k = n*1ll*(m-1);
        cout<<k<<endl;
    }
    return 0;
}