#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int long long
#define endl "\n"
const LL mod = 1e9 + 7;

vector<LL> prefix_function(string s)
{
    LL n = (LL)s.length();
    vector<LL> pi(n);
    for (LL i = 1; i < n; i++)
    {
        LL j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

LL bin(LL a, LL p)
{
    if (p == 0)
        return 1;
    LL res = bin(a, p / 2ll);
    res = (res * res) % mod;
    if (p & 1ll)
        res = (res * a) % mod;
    return res;
}

LL mmi(LL a)
{
    return bin(a, mod - 2);
}

const LL sz = 1e7 + 5;
vector<LL> primes;
void sieve()
{
    vector<bool> isp(sz, true);
    isp[0] = false, isp[1] = false;
    for (LL i = 2; i * i <= sz; i++)
        if (isp[i])
            for (LL j = i * i; j < sz; j += i)
                isp[j] = false;
    for (int i = 2; i < sz; i++)
        if (isp[i])
            primes.push_back(i);
}

int dfs(int sc, int par, vector<int> v[], vector<int> &depth)
{
    depth[sc]++;
    for (auto &val : v[sc])
        if (val != par)
            depth[sc] += dfs(val, sc, v, depth);
    return depth[sc];
}

void solve()
{
    int n, x, y;
    cin >> n;
    vector<pair<int, int>> vp(n);
    vector<int> v[n + 1], depth(n + 1);
    for (int _ = 1; _ < n ; _++)
    {
        cin >> x >> y;
        vp[_].first = x, vp[_].second = y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, 0, v, depth);
    for (auto &val : vp)
        if (depth[val.second] > depth[val.first])
            swap(val.first, val.second);
    vector<int> res;
    for (int i = 1; i < vp.size(); i++)
    {
        auto val = vp[i];
        // cout << val.first << " " << val.second << " -->  ";
        // cout << n - depth[val.second] << " " << depth[val.second] << endl;
        res.push_back((n - depth[val.second]) * depth[val.second]);
    }
    sort(res.begin(), res.end());
    int m;
    cin >> m;
    vector<int> fact(m);
    for (auto &val : fact)
        cin >> val;
    while (fact.size() < (n - 1))
        fact.push_back(1);
    sort(fact.begin(), fact.end());
    // for (auto &val : res)
    //     cout << val << " ";
    // cout << endl;
    // for (auto &val : fact)
    //     cout << val << " ";
    // cout << endl;
    int ans = res.back();
    res.pop_back();
    while (fact.size() != res.size())
    {
        ans = (ans * fact.back()) % mod;
        fact.pop_back();
    }
    // cout << ans << endl;
    while (fact.size() && res.size())
    {
        ans = (ans + (fact.back() * res.back()) % mod) % mod;
        fact.pop_back(), res.pop_back();
    }
    cout << ans << endl;
}
signed main()
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