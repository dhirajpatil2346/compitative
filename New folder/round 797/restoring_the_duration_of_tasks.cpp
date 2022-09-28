#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin >> n;
    vector<int> v1(n), v2(n), v3(n);
    for (auto &val : v1)
    {
        cin >> val;
    }
    for (auto &val : v2)
    {
        cin >> val;
    }
    int curr = v1[0];
    for (int i = 0; i < n; i++)
    {
        // cout<<curr<<"   "<<v1[i]<<endl;
        int z = max(v1[i], curr);
        v3[i] = v2[i] - z;
        curr = v2[i];
    }
    for(auto &val:v3)
    {
        cout<<val<<" ";
    }
    cout<<endl;
    }
    return 0;
}