#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(n), p(m);
    for (auto &val : v)
    {
        cin >> val;
    }
    for (auto &val : p)
    {
        cin >> val;
    }
    sort(p.rbegin(), p.rend());
    for (int i = 0; i < m; i++)
    {
        int x = v[p[i] - 1], y = v[p[i]];
        cout << x << "  " << y << endl;
        if (x <= y)
        {
            continue;
        }
        else
        {
            auto temp = v[p[i] - 1];
            v[p[i] - 1] = v[p[i]];
            v[p[i]] = temp;
        }
    }
    for (auto &val : v)
    {
        cout << val << " ";
    }
    cout << endl;
    vector<int> vn = v;
    sort(vn.begin(), vn.end());
    if (v == vn)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}