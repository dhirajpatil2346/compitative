#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    map<int, vector<int>> m;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        m[x].push_back(y);
    }
    int p = 0, lp = 0, x = 0;
    int cp = 0;
    vector<int> vct;
    for (auto &val : m)
    {
        vct.push_back(val.first);
        sort(val.second.begin(), val.second.end());
    }
    for (auto it = m.rbegin();it!=m.rend();it++)
    {
        pair<int, vector<int>>val=*it;
        lp = cp;
        //cout<<cp<<endl;
        if (val.second.size() + cp >= k-1)
        {
            //cout<<val.first<<endl;
            x = val.first;
            int req = k - lp-1;
            p = val.second[req];
            break;
        }
        cp += val.second.size();
    }
    //cout << x<<"  "<<p << endl;
    int ans = 0;
    for (auto &val : m[x])
    {
        if (val == p)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}