#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n+1);
    map<pair<int,int>, int> m;
    for(int i = 1 ; i<=n ;i++)
    {
        cin>>v[i];
    }
    for(int i = 1 ; i <= n ; i++)
    {
        int d=0;
        for (int j = i+1; j <= n; j++)
        {
            if(v[j]>=v[j-1])
            {
                m[{i,j}]=d;
            }
            else
            {
                d+=abs(v[j]-v[j-1]);
                m[{i,j}]=d;
            }
        }
    }
    for(int i = n ; i > 1 ; i--)
    {
        int d=0;
        for (int j = i-1; j >= 0; j--)
        {
            if(v[j]>=v[j+1])
            {
                m[{i,j}]=d;
            }
            else
            {
                d+=abs(v[j+1]-v[j]);
                m[{i,j}]=d;
            }
        }
    }
    while(k--)
    {
        int i,j;
        cin>>i>>j;
        cout<<m[{i,j}]<<endl;
    }
    return 0;
}