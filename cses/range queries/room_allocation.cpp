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

struct query
{
    int i, d, ind;
    query()
    {
    }
    query(int I, int D, int indi)
    {
        i = I, d = D, ind = indi;
    }
};

bool cmp(query &a, query &b)
{
    if (a.i != b.i)
        return a.i < b.i;
    return a.d < b.d;
}

void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> vp(n);
    vector<int> v;
    vector<query> vq(n);
    int o = 0;
    for (auto &val : vp)
    {
        cin >> val.first >> val.second;
        v.push_back(val.first), v.push_back(val.second);
        vq[o] = query(val.first, val.second, o);
        o++;
    }
    sort(vq.begin(), vq.end(), cmp);
    sort(v.begin(), v.end());
    int cnt = 0;
    unordered_map<int, int> value_to_pt;
    value_to_pt[v[0]] = cnt;
    cnt++;
    for (int i = 1; i < 2 * n; i++)
        if (v[i] != v[i - 1])
        {
            value_to_pt[v[i]] = cnt;
            cnt++;
        }
    vector<int> pref(cnt);
    for (auto &val : vp)
    {
        pref[value_to_pt[val.first]]++;
        if ((value_to_pt[val.second] + 1) < pref.size())
            pref[(value_to_pt[val.second] + 1)]--;
    }
    for (int i = 1; i < pref.size(); i++)
        pref[i] += pref[i - 1];
    int sz = *max_element(pref.begin(), pref.end());
    set<pair<int, int>> s;
    for (int i = 1; i <= sz; i++)
        s.insert({0, i});
    vector<int> ans(n);
    for (auto &val : vq)
    {
        ans[val.ind] = (*s.begin()).second;
        auto y = *s.begin();
        s.erase(s.begin());
        y.first = val.d;
        s.insert(y);
    }
    cout << sz << endl;
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