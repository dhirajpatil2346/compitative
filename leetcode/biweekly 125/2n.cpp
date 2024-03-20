#include <bits/stdc++.h>
using namespace std;
#define LL long long
// #define int long long
#define endl "\n"
#define Endl "\n"
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

int dfs(int sc, int par, vector<pair<int, int>> v[], int curr, int &sp)
{
    int ret = 0;
    if (curr % sp == 0)
    {
        ret++;
    }
    for (auto &child : v[sc])
        if (child.first != par)
        {
            // cout << child.first << " " << curr + child.second << endl;
            ret += dfs(child.first, sc, v, curr + child.second, sp);
        }
    return ret;
}
vector<int> solve()
{
    int n, sp;
    cin >> n >> sp;
    vector<pair<int, int>> v[n + 1];
    for (int i = 0; i < n - 1; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        v[x].push_back({y, z});
        v[y].push_back({x, z});
    }
    vector<int> ret;
    // return ret;
    for (int i = 0; i < n; i++)
    {
        vector<int> cz;
        for (auto &child : v[i])
        {
            // cout << child.first << endl;
            int o = dfs(child.first, i, v, child.second, sp);
            if (o != 0)
                cz.push_back(o);
            // cout << i << " " << child.first << " " << o << endl;
        }
        int op = accumulate(cz.begin(), cz.end(), 0);
        int ans = 0;
        if (cz.size() == 1)
        {
        }
        else
        {
            for(auto &val:cz)
            {
                ans+= val*(op-val);
            }
        }
        // ret.push_back(ans);
        ret.push_back(ans/2);
    }
    return ret;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}