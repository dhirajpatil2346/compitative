#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, u;
    cin >> n >> m >> u;
    vector<int> v(n);
    for (auto &val : v)
    {
        cin >> val;
    }
    int z = ceil(sqrt(n));
    vector<int> pre(z, INT_MAX);
    for (int i = 0; i < n; i++)
    {
        pre[i / z] = min(pre[i / z], v[i]);
    }
    while (m--)
    {
        int l, r, u, p;
        cin >> l >> r >> u >> p;
        
    }
    return 0;
}