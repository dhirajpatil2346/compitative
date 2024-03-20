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

void build(LL ind, vector<LL> &a, vector<LL> &v, LL l, LL r)
{
    if (r <= l)
        return;
    LL mid = (l + r) / 2ll;
    build(ind * 2ll, a, v, l, mid);
    build(ind * 2ll + 1ll, a, v, mid + 1ll, r);
    a[ind] = __gcd(a[ind * 2ll], a[ind * 2ll + 1ll]);
    if ((mid + 1ll) < v.size())
        a[ind] = __gcd(a[ind], abs(v[mid] - v[mid + 1ll]));
}

LL gt(LL ind, vector<LL> &a, LL l, LL r, LL L, LL R, vector<LL> &v)
{
    if (r <= l || r < L || l > R)
        return 0;
    if (l >= L && r <= R)
        return a[ind];
    LL mid = (l + r) / 2ll;
    LL g = __gcd(gt(ind * 2ll, a, l, mid, L, R, v), gt(ind * 2ll + 1ll, a, mid + 1ll, r, L, R, v));
    if (mid >= L && (mid + 1ll) <= R)
        g = __gcd(g, abs(v[mid] - v[mid + 1ll]));
    return g;
}

void solve()
{
    LL n;
    cin >> n;
    vector<LL> v(n), a(4 * n);
    for (auto &val : v)
        cin >> val;
    int lg[n + 1];
    lg[1] = 0;
    for (int i = 2; i <= n; i++)
        lg[i] = lg[i / 2] + 1;
    vector<vector<LL>> dp(n, vector<LL>(30));
    for (LL i = 1; i < 28 && (1 << i) <= n; i++)
        for (LL j = 0; (j + (1 << i)) <= n; j++)
            dp[j][i] = __gcd(__gcd(dp[j][i - 1], dp[j + (1 << (i - 1))][i - 1]), abs(v[j - 1 + (1 << (i - 1))] - v[j + (1 << (i - 1))]));
    LL ans = 1, l = 2, r = n;
    while (l <= r)
    {
        LL mid = (l + r) / 2ll;
        LL lk = lg[mid];
        bool got = false;
        for (LL i = 0; (i + mid) <= n && (!got); i++)
        {
            LL L = i, R = i + mid - 1ll;
            LL j = i + (1 << lk) - 1;
            LL x = __gcd(dp[L][lk], dp[R - (1 << lk) + 1][lk]);
            if (x != 1)
            {
                // cout << i << " " << j << " " << mid << endl;
            }
            if (x != 1)
            {
                got = true;
                break;
            }
        }
        if (got)
        {
            // if(x!=1)
            // cout << mid << endl;
            ans = mid;
            l = mid + 1ll;
            // cout << got << endl;
            // cout << l << " " << r << endl;
        }
        else
            r = mid - 1ll;
    }
    cout << ans << endl;
}
int main()
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