#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

vector<int> cmp(vector<LL> &v, vector<int> &v1, vector<int> &v2)
{
    vector<int> ret;
    int cnt = 0; // to track ret array
    int i = 0;   // for v1
    int j = 0;   // for v2
    while (cnt < 4 && i < v1.size() && j < v2.size())
    {

        if ((v[v1[i]] >= v[v2[j]]) && v[v1[i]] != 0)
            ret.push_back(v1[i]);
        else if (v[v2[j]] != 0)
            ret.push_back(v2[j]);
        else
            break;
        cnt++, i++, j++;
    }
    while (cnt < 4 && i < v1.size())
    {
        ret.push_back(v1[i++]);
        cnt++;
    }
    while (cnt < 4 && j < v2.size())
    {
        ret.push_back(v2[j++]);
        cnt++;
    }
    return ret;
}

void update(vector<vector<int>> &a, int ind, vector<LL> &v, int l, int r, int &pos, int &value)
{
    if (l == r)
    {
        v[pos] = value;
        a[ind][0] = pos;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
        update(a, 2 * ind, v, l, mid, pos, value);
    else
        update(a, 2 * ind + 1, v, mid + 1, r, pos, value);
    cmp(v, a[2 * ind], a[2 * ind + 1]);
}

void build(vector<vector<int>> &a, int ind, vector<LL> &v, int l, int r)
{
    if (l == r)
    {
        a[ind].push_back(l);
        return;
    }
    int mid = (l + r) / 2;
    build(a, 2 * ind, v, l, mid);
    build(a, 2 * ind + 1, v, mid + 1, r);
    a[ind] = cmp(v, a[2 * ind], a[2 * ind + 1]);
}

void solve()
{
    int n;
    cin >> n;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    vector<vector<int>> a(4 * n);
    build(a, 1, v, 0, n - 1);
    for (auto &val : a[1])
        cout << val << " ";
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}