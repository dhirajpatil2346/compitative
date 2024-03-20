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
int block = 1;
struct query
{
    int l, r, ind;
    query() {}
    query(int L, int R, int I)
    {
        l = L, r = R, ind = I;
    }
};
 
bool cmp(query &a, query &b)
{
    if ((a.l / block) != b.r / block)
        return ((a.l / block) < (b.l / block));
    return a.r < b.r;
}
 
void solve()
{
    int n, q;
    cin >> n >> q;
    block = sqrt(n);
    vector<int> v(n), ans(q);
    vector<query> Q(q);
    for (auto &val : v)
        cin >> val;
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        Q[i] = query(l, r, i);
    }
    sort(Q.begin(), Q.end(), cmp);
    int L = 0, R = 0;
    unordered_map<int, int> m;
    for (auto &val : Q)
    {
        int l = val.l, r = val.r;
        while (L < l) // current is behind need so include it
            m[v[L++]]++;
 
        while (l < L)
        {
            //  exclude it
            m[v[L]]--;
            if (m[v[L]] == 0)
                m.erase(v[L]);
            L--;
        }
 
        while (r + 1 < R)
        {
            R--;
            m[v[R]]--;
            if (m[v[R]] == 0)
                m.erase(v[R]);
        }
        while (r + 1 > R)
        {
            m[v[R++]]++;
        }
        ans[val.ind] = m.size();
    }
    for (auto &val : ans)
        cout << val << "\n";
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