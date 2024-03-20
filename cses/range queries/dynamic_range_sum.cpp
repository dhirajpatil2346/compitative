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

vector<LL> a(8 * (int)1e5);
void up(int ind, int l, int r, int pos, LL val)
{
    if (r < l)
        return;
    if (l == r)
    {
        a[ind] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
        up(ind * 2, l, mid, pos, val);
    else
        up(ind * 2 + 1, mid + 1, r, pos, val);
    a[ind] = a[ind * 2] + a[ind * 2 + 1];
}

LL gt(int ind, int l, int r, int L, int R)
{
    if (r < l || r < L || l > R)
        return 0;
    if (l >= L && r <= R)
        return a[ind];
    int mid = (l + r) / 2;
    return gt(ind * 2, l, mid, L, R) + gt(ind * 2 + 1, mid + 1, r, L, R);
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> dp(n);
    cin >> dp[0];
    for (int i = 1; i < n; i++)
    {
        cin >> dp[i];
        dp[i] ^= dp[i - 1];
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int ans = dp[r];
        if (l > 0)
            ans ^= dp[l - 1];
        cout << ans << endl;
    }
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