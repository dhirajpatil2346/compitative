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

const LL sz = sqrt(3e7 / 2) + 5;
vector<LL> primes;
vector<int> facts((3e7 / 2) + 5);
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
void fs()
{
    for (int i = 0; i < facts.size(); i++)
        facts[i] = i;
    for (int i = 2; i * i <= facts.size(); i++)
    {
        if (facts[i] != i)
            continue;
        for (int j = i * i; j < facts.size(); j += i)
            if (facts[j] == j)
                facts[j] = i;
    }
}
void solve()
{
    unordered_map<int, int> m;
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        unordered_map<int, int> cm;
        int x = v[i];
        while (x > 1)
        {
            cm[facts[x]]++;
            x /= facts[x];
        }
        for (auto &val : cm)
        {
            int c = 1;
            for (int _ = 0; _ < val.second; _++)
            {
                c *= val.first;
                m[c]++;
            }
        }
    }
    int maxi = 0;
    for (auto &val : m)
    {
        if (val.second == n || val.second == 0)
            continue;
        maxi = max(maxi, val.second);
    }
    maxi = n - maxi;
    if (maxi == n)
        maxi = -1;
    cout << maxi << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // cout << sz << endl;
    sieve();
    fs();
    solve();
    return 0;
}