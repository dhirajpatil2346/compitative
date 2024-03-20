#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
vector<int> primes;
vector<pair<int, int>> vp;
vector<int> ans(1e6 + 1);
int bin(int n, int l, int r)
{
    if (r < l)
        return -1;
    int mid = (l + r) / 2;
    if (vp[mid].first <= n)
    {
        int right = bin(n, mid + 1, r);
        if (right != -1)
            return right;
        return mid;
    }
    return bin(n, l, mid - 1);
}
int binsq(int n, int l, int r)
{
    if (r < l)
        return -1;
    int mid = (l + r) / 2;
    if (vp[mid].second <= n)
    {
        int right = binsq(n, mid + 1, r);
        if (right != -1)
            return right;
        return mid;
    }
    return binsq(n, l, mid - 1);
}

void sieve()
{
    vector<bool> p(1e6 + 1, true);
    p[0] = false, p[1] = false;
    for (int i = 2; i < p.size(); i++)
        if (p[i])
            for (int j = 2 * i; j < p.size(); j += i)
                p[j] = false;
    for (int i = 2; i < p.size(); i++)
        if (p[i])
            primes.push_back(i);
    for (int i = 0; i < primes.size() && ((primes[i] * primes[i]) <= 1e6); i++)
        vp.push_back({primes[i], primes[i] * primes[i]});
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 3;
    int cnt = 2;
    for (int i = 4; i <= 1e6; i++)
    {
        int under = bin(i, 0, vp.size() - 1);
        int tr = binsq(i, 0, vp.size() - 1);
        if (p[i])
            cnt++;
        ans[i] = cnt;
        ans[i] -= (tr);
    }
}

void solve()
{
    int n;
    cin >> n;
    cout << ans[n] << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}