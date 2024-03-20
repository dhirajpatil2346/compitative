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

int make(int l, int r, int ch, vector<vector<int>> &v)
{
    int pos = ch - 'a';
    int f = v[r][pos];
    if (l > 0)
        f -= v[l - 1][pos];
    return (r - l + 1) - f;
}

int f(int l, int r, string &s, char ch, vector<vector<int>> &v)
{
    if (l == r)
    {
        return s[l] != ch;
    }
    int ret = 1e9, mid = (l + r) / 2;
    // make first half and go for next
    // cout << l + 1 << " " << mid + 1 << " " << ch << " " << make(l, mid, ch, v) << endl;
    ret = min(ret, make(l, mid, ch, v) + f(mid + 1, r, s, ch + 1, v));
    // make second half and go for prev
    ret = min(ret, f(l, mid, s, ch + 1, v) + make(mid + 1, r, ch, v));
    return ret;
}

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    vector<vector<int>> v(n, vector<int>(26));
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            v[i] = v[i - 1];
        v[i][s[i] - 'a']++;
    }
    cout << f(0, n - 1, s, 'a', v) << endl;
}
signed main()
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