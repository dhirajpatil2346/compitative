#include <bits/stdc++.h>
using namespace std;

int sum(vector<int> &t, int v, int tl, int tr, int l, int r)
{
    // cout << tl << " " << tr << " " << l << " " << r << endl;
    if (l > r)
        return 0;
    if (r < tl)
        return 0;
    if (l > tr)
        return 0;
    if (l >= tl && r <= tr)
    {
        return t[v];
    }
    int tm = (l + r) / 2;
    return sum(t, v * 2, tl, tr, l, tm) | sum(t, v * 2 + 1, tl, tr, tm + 1, r);
}
void build(vector<int> &t, vector<int> &a, int v, int tl, int tr)
{
    if (tl == tr)
    {
        t[v] = a[tl];
    }
    else
    {
        int tm = (tl + tr) / 2;
        build(t, a, v * 2, tl, tm);
        build(t, a, v * 2 + 1, tm + 1, tr);
        t[v] = t[v * 2] | t[v * 2 + 1];
    }
}

vector<int> binaryQueries(int n, vector<int> &a, int q, vector<vector<int>> &queries)
{
    // Write your code here.
    vector<int> pos;
    vector<int> t(4 * n);
    build(t, a, 1, 0, n - 1);
    for (auto &val : queries)
    {
        // cout << 1 << endl;
        int o = sum(t, 1, val[0], val[1], 0, n - 1);
        cout << o << endl;
        pos.push_back(val[2] ^ o);
    }
    return pos;
}

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int n;
    cin >> n;
    int q;
    cin >> q;
    vector<int> a(n);
    for (auto &val : a)
        cin >> val;
    vector<vector<int>> queries(q, vector<int>(3));
    for (auto &val : queries)
        cin >> val[0] >> val[1] >> val[2];
    vector<int> v = binaryQueries(n, a, q, queries);
    for (auto &val : v)
        cout << val << " ";
    cout << endl;
    return 0;
}