#include <bits/stdc++.h>
using namespace std;
#define LL long long
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

bool detect(int sc, int par, vector<int> v[], vector<int> &pos, int curr)
{
    char ch;
    // cout << sc << " " << pos[sc] << endl;
    // cin >> ch;
    if (pos[sc] == -1)
        pos[sc] = curr;
    else
    {
        if ((curr - pos[sc]) & 1)
            return false;
        return true;
    }
    bool ret = true;
    for (auto &child : v[sc])
        if (child != par)
            ret &= detect(child, sc, v, pos, curr + 1);
    return ret;
}

void dfs(int sc, vector<int> &lvl, vector<int> v[], int curr)
{
    if (lvl[sc] != -1 || v[sc].size() == 0)
        return;
    curr %= 2;
    lvl[sc] = curr;
    for (auto &child : v[sc])
        dfs(child, lvl, v, curr + 1);
}

void solve()
{
    LL n, m;
    cin >> n >> m;
    vector<int> v[n + 1], lvl(n + 1, -1), pos(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
        if (pos[i] == -1)
            if (!(detect(i, 0, v, pos, 0)))
            {
                cout << -1 << endl;
                return;
            }
    for (int i = 1; i <= n; i++)
        dfs(i, lvl, v, 0);
    cout << count(lvl.begin(), lvl.end(), 0) << endl;
    for (int i = 1; i <= n; i++)
        if (lvl[i] == 0)
            cout << i << " ";
    cout << endl;
    cout << count(lvl.begin(), lvl.end(), 1) << endl;
    for (int i = 1; i <= n; i++)
        if (lvl[i] == 1)
            cout << i << " ";
    cout << endl;
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