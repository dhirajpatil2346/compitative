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

vector<int> p_pow((int)(1e5 + 5), 1);
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> v(n);
    int tot = 0;
    for (int i = 0; i < n; i++)
    {
        int b = s[i] - 'a' + 1;
        v[i] = (b * p_pow[i]) % mod;
        tot = (tot + v[i]) % mod;
    }
    set<int> st;
    // st.insert(tot);
    for (int i = 0; i <= n - 3; i++)
    {
        int curr = tot;
        string h = "";
        h.push_back(s[i + 1]);
        h.push_back(s[i + 2]);
        h.push_back(s[i]);
        // cout << curr << endl;
        for (int k = i; k <= i + 2; k++)
        {
            curr = (curr - v[i] + mod) % mod;
        }
        for (int k = i, j = 0; k <= i + 2; k++, j++)
        {
            int b = h[j] - 'a' + 1;
            b = (b * p_pow[k]) % mod;
            curr = (curr + b) % mod;
        }
        // cout << i << " " << curr << endl;
        st.insert(curr);
    }
    cout << st.size() << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 1; i < p_pow.size(); i++)
    {
        int ten = 31;
        p_pow[i] = (p_pow[i - 1] * ten) % mod;
    }
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}