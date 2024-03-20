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
    LL n, m;
    cin >> n;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    vector<pair<LL, LL>> smallpref(n), bigpref(n), smallsuff(n), bigsuff;
    multiset<int> s;
    s.insert(v[0]);
    for (int i = 1; i < n; i++)
    {
        s.insert(v[i]);
        smallpref[i] = {*s.begin(), *next(s.begin())};
        bigpref[i] = {*prev(s.end()), *prev(prev(s.end()))};
    }
    s.clear();
    s.insert(v.back());
    for (int i = n - 2; i >= 0; i--)
    {
        s.insert(v[i]);
        smallsuff[i] = {*s.begin(), *next(s.begin())};
        bigsuff[i] = {*prev(s.end()), *prev(prev(s.end()))};
    }
    // smallpref and suffmax
    // bigpref and smallsuff
    bool g = false;
    for (int i = 1; i <= n - 2; i++)
    {
        pair<int, int> p1 = smallpref[i], p2 = bigsuff[i + 1];
        if(p1.first+p1.second!= p2.first+p2.second) g=true;
        p1 = bigpref[i],p2 = smallsuff[i+1];
        if(p1.first+p1.second!= p2.first+p2.second) g=true;
    }
    if (g)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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