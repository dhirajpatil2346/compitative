#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    map<pair<int,int>,int>ans;
    for(auto &val:v)
    {
        cin>>val;
    }
    map<int, vector<int>>m;
    while(k--)
    {
        int x,y;
        cin>>x>>y;
        m[x].push_back(y);
    }
    for(auto &val:m)
    {
        sort(val.second.begin(), val.second.end());
    }
    for(auto &val:m)
    {
        int d=0;
        int start = val.second[0];
        int n = val.second.size();
        
    }
    return 0;
}