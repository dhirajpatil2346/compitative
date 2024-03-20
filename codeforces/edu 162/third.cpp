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

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    vector<int> rq = v;
    for (auto &val : rq)
        if (val > 1)
            val = 1;
        else
            val = 2;
    for (int i = 1; i < n; i++)
        v[i] += v[i - 1];
    for (int i = 1; i < n; i++)
        rq[i] += rq[i - 1];
    // for (auto &val : v)
    //     cout << val << " ";
    // cout << endl;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (l == r)
            cout << "NO" << endl;
        else
        {
            int sum = v[r];
            if (l > 0)
                sum -= v[l - 1];
            int need = rq[r];
            if (l > 0)
                need -= rq[l - 1];
            if (sum >= need)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}

/*
3=> 4 -> 1 1 1 -> 2 2 2
4 => 1 1 1 1 => 2 2 2 2
*/
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