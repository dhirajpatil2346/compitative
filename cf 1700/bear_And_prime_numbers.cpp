#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

void func(vector<LL> &f, map<LL, LL> &m)
{
    vector<LL> v(1e7 + 1, 0);
    for (LL i = 0; i < v.size(); i++)
        v[i] = i;
    for (LL i = 2; i * i <= 1e7; i++)
        if (v[i] == i)
            for (LL j = i * i; j <= 1e7; j += i)
                v[j] = i;
    for (auto &val : m)
    {
        LL i = val.first;
        LL cal = i;
        set<LL> s;
        while (cal > 1)
        {
            s.insert(v[cal]);
            cal /= v[cal];
        }
        for (auto &valu : s)
            f[valu] += val.second;
    }
}

void solve()
{
    LL n;
    cin >> n;
    map<LL, LL> m;
    for (LL i = 0; i < n; i++)
    {
        LL x;
        cin >> x;
        m[x]++;
    }
    vector<LL> f(1e7 + 100);
    func(f, m);
    for (LL i = 1; i <= 1e7; i++)
        f[i] += f[i - 1];
    LL q;
    cin >> q;
    while (q--)
    {
        LL x, y;
        cin >> x >> y;
        if (x > 1e7)
        {
            cout << 0 << endl;
            continue;
        }
        y = min((long long)1e7, y);
        x--;
        // cout<<x<<" "<<y<<endl;
        LL z = f[y] - f[x];
        cout << z << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}