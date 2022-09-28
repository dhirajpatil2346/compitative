#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        m[x]++;
    }
    int maxi = INT_MIN;
    for (auto &val:m)
    {
        maxi=max(maxi, val.second);
    }
    if(!(n%2))
    {
        if(maxi<=n/2)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    else
    {
        if((maxi)<=(n+1)/2)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}