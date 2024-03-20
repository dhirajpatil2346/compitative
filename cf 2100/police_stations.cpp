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

void solve()
{
    int n, k, d;
    cin >> n >> k >> d;
    vector<int> roads(k), v[n + 1], lvl(n + 1, -1), par(n + 1);
    queue<pair<int, int>> q;
    for (auto &val : roads)
    {
        cin >> val;
        lvl[val] = d;
        q.push({val, lvl[val]});
    }
    map<pair<int, int>, int> ind;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
        ind[{x, y}] = i, ind[{y, x}] = i;
    }

    set<int> ans;
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        for (auto &val : v[p.first])
        {
            if (val == par[p.first])
                continue;
            if (lvl[val] != -1 || lvl[val] == 0)
            {
                ans.insert(ind[{p.first, val}]);
            }
            else
            {
                par[val] = p.first;
                lvl[val] = p.second - 1;
                q.push({val, lvl[val]});
            }
        }
    }
    cout << ans.size() << endl;
    for (auto &val : ans)
        cout << val << " ";
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