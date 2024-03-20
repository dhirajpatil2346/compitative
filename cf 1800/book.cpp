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

bool cycle(int sc, set<int> &vis, vector<int> v[])
{
    if (vis.find(sc) != vis.end())
    {
        return v[sc].size();
    }
    vis.insert(sc);
    bool ret = false;
    for (auto &child : v[sc])
        ret |= cycle(child, vis, v);
    return ret;
}

void topo(int sc, vector<bool> &vis, vector<int> v[], vector<int> &curr)
{
    if (vis[sc])
        return;
    vis[sc] = true;
    for (auto &val : v[sc])
        topo(val, vis, v, curr);
    curr.push_back(sc);
}

int solve()
{
    int n, k, x;
    cin >> n;
    set<pair<int, int>> s;
    vector<int> par[n + 1], v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> k;
        while (k--)
        {
            cin >> x;
            par[x].push_back(i);
            v[i]++;
        }
        s.insert({v[i], i});
    }
    // cout << "here" << endl;
    int c = 0, prv = -1;
    while (s.size())
    {
        c++;
        // cout << endl
        //      << c << endl;
        // for (auto &val : s)
        //     cout << val.first << " " << val.second << endl;
        // cout << endl;
        if ((s.begin()->first) != 0)
            return -1;
        set<int> z;
        while (s.size())
        {
            auto p = *s.begin();
            // cout << p.first << " " << p.second << Endl;
            if ((s.begin()->first) != 0 || (s.begin()->second)< prv) break;
            s.erase(s.begin());
            int pt = p.second;
            for (auto &parents : par[pt])
            {
                s.erase({v[parents], parents});
                v[parents]--;
                if (parents > pt)
                {
                    // cout << parents << endl;
                    s.insert({v[parents], parents});
                }
                else
                    z.insert(parents);
            }
            
            prv = p.second;
        }
        for (auto &val : z)
                s.insert({v[val], val});
        prv = -1;
        // cout << Endl;
    }
    return c;
}
signed main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        cout << solve() << endl;
    }
    return 0;
}
/*



*/