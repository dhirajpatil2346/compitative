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

bool f(LL sc, LL par, vector<LL> &dp, vector<LL> &h, vector<LL> v[], LL ap, LL an)
{
    // cout << sc << " " << ap << " " << an << endl;
    if (ap < 0 || an < 0)
        return true;
    bool ret = false;
    for (auto &c : v[sc])
    {
        if (c == par)
            continue;
        int pos = dp[c] + h[c];
        if (pos & 1)
        {
            return true;
        }
        pos >>= 1;
        if (pos > ap)
            return true;
        LL neg = dp[c] - pos;
        ap -= pos;
        if (neg <= an)
            an -= neg;
        else
        {
            LL curr = an;
            an -= curr;
            ap -= (neg - curr);
        }
        ret |= f(c, sc, dp, h, v, pos, neg);
    }
    // cout << "   " << sc << " " << ret << endl;
    return ret;
}

LL sum(LL c, LL par, vector<LL> &a, vector<LL> v[], vector<LL> &dp)
{
    LL ret = a[c];
    for (auto &child : v[c])
    {
        if (child == par)
            continue;
        ret += sum(child, c, a, v, dp);
    }
    return dp[c] = ret;
}

bool solve()
{
    LL n, m;
    cin >> n >> m;
    vector<LL> a(n + 1);
    vector<LL> h(n + 1);
    vector<LL> v[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    vector<LL> dp(n + 1);
    sum(1, 0, a, v, dp);
    bool fault = false;
    if ((dp[1] + h[1]) & 1ll)
        fault = true;
    LL pos = (dp[1] + h[1]) / 2ll;
    LL neg = dp[1] - pos;
    if (neg < 0 || pos < 0)
        fault = true;
    // cout << pos << " " << neg << endl;
    fault |= f(1, 0, dp, h, v, pos, neg);
    return fault;
}
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        if (!solve())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}