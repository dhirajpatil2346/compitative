#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n, l, r, s;
    cin >> n >> l >> r >> s;
    vector<int> v(n + 1);
    int elereq = r - l;
    int sum = (elereq * (elereq + 1)) / 2;
    set<int> vis;
    int R = s - sum;
    bool got = false;
    if (l == r)
    {
        v[l] = s;
        vis.insert(s);
        for (int i = 1, j = 1; i <= n; i++)
        {
            if (v[i] != 0)
                continue;
            while (vis.find(j) != vis.end())
                j++;
            v[i] = j;
            vis.insert(j);
        }
        if (*max_element(v.begin(), v.end()) > n)
        {
            cout << -1 << endl;
            return;
        }
        for (int i = 1; i <= n; i++)
            cout << v[i] << " ";
        cout << endl;
        return;
    }
    if (R > elereq)
    {
        got = true;
        v[l] = R;
        vis.insert(R);
        for (int p = l + 1, ele = 1; p <= r; p++, ele++)
        {
            v[p] = ele;
            vis.insert(ele);
        }
    }
    else
    {
        for (int i = 1, j = elereq + 1; (j <= n) && (got == false); j++)
        {
            sum -= i, sum += j;
            R = s - sum;
            if (R > 0 && R <= n && ((R <= i) || (R > j)))
            {
                got = true;
                v[l] = R;
                vis.insert(R);
                for (int p = l + 1, ele = i + 1; p <= r; p++, ele++)
                {
                    v[p] = ele;
                    vis.insert(ele);
                }
            }
        }
    }
    for (int i = 1, j = 1; i <= n; i++)
    {
        if (v[i] != 0)
            continue;
        while (vis.find(j) != vis.end())
            j++;
        v[i] = j;
        vis.insert(j);
    }
    if (*max_element(v.begin(), v.end()) > n)
    {
        cout << -1 << endl;
        return;
    }
    if (!got)
    {
        cout << -1 << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
        cout << v[i] << " ";
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