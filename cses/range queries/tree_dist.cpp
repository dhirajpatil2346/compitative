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

int gt(int sc, int par, set<pair<int, int>> depth[])
{
    if (sc == 1)
        return -1;
    for (auto it = depth[par].rbegin(); it != depth[par].rend(); it++)
        if (it->second != sc)
            return it->first;
    return 0;
}

int dfs(int sc, int par, vector<int> v[], vector<int> &down, set<pair<int, int>> depth[])
{
    int ans = 0;
    // enter into child
    for (auto &child : v[sc])
    {
        if (child == par)
            continue;
        int curr = 1 + dfs(child, sc, v, down, depth);
        ans = max(ans, curr);
        depth[sc].insert({curr, child});
        if (depth[sc].size() > 2)
            depth[sc].erase(depth[sc].begin());
    }
    // return
    return down[sc] = ans;
}
void f(int sc, int par, vector<int> v[], vector<int> &answer, vector<int> &up, vector<int> &down, set<pair<int, int>> depth[])
{
    up[sc] = 1 + max(up[par], gt(sc, par, depth));
    // cout << sc << " " << up[par] << " " << gt(sc, par, depth) << endl;
    answer[sc] = max(up[sc], down[sc]);
    for (auto &child : v[sc])
        if (child != par)
            f(child, sc, v, answer, up, down, depth);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v[n + 1], up(n + 1), down(n + 1), answer(n + 1);
    set<pair<int, int>> depth[n + 1];
    up[0] = -1;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1, 0, v, down, depth);
    f(1, 0, v, answer, up, down, depth);
    // for (int i = 1; i <= n; i++)
    //     cout << down[i] << " ";
    // cout << endl;
    // for (int i = 1; i <= n; i++)
    // cout << endl;
    for (int i = 1; i <= n; i++)
        cout << answer[i] << " ";
    cout << endl;
}
int main()
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

/*

        1
      /   \
    2      3
        /    \
      4        5

*/