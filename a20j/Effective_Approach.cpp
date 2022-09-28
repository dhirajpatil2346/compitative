#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int y = pow(10,5);
    int pos[y];
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        pos[x]=i;
    }
    int q;
    cin>>q;
    long long l=0, r=0;
    for (int i = 0; i < q; i++)
    {
        int x;
        cin>>x;
        l+=pos[x]+1;
        r+=n-pos[x];
    }
    cout<<l<<" "<<r;
    return 0;
}