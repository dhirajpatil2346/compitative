#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
     n = 2*(n-1);
    long long j = 1;
    for(int i = 1 ; i<=n;i++)
    {
        j = j * 1ll * i;
    }
    cout<<j<<endl;
    return 0;
}