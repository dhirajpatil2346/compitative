#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int long long
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

void dfs(int sc, int par, vector<int> v[], vector<int> &a, vector<pair<int, int>> &track)
{
    if (a[sc] == 1)
        track[sc].second++;
    else
        track[sc].first++;
    for (auto &val : v[sc])
        if (val != par)
        {
            dfs(val, sc, v, a, track);
            track[sc].first += track[val].first;
            track[sc].second += track[val].second;
        }
}

void f(int sc, int par, vector<int> v[], vector<pair<int, int>> &track, vector<int> &ans)
{
    ans[sc] = max(ans[par], abs(track[sc].first - track[sc].second));
    for (auto &val : v[sc])
        if (val != par)
            f(val, sc, v, track, ans);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), v[n + 1], ans(n + 1, 0);
    vector<pair<int, int>> track(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, 0, v, a, track);
    f(1, 0, v, track, ans);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
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