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

bool solve()
{
    int n, k;
    cin >> n >> k;
    map<int, int> m;
    vector<int> h(n);
    for (auto &val : h)
    {
        cin >> val;
    }
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        p = abs(p);
        m[p] += h[i];
    }
    int p = 0, b = 0;
    for (auto &val : m)
    {
        int dist = val.first - p;
        if (dist <= 0)
            return false;
        if (val.second <= b)
        {
            b -= val.second;
        }
        else
        {
            // difference is greater
            int need = val.second - b;
            int round = need / k;
            if (need % k)
                round++;
            if (round > dist)
                return false;
            b += (round * k);
            b -= val.second;
            p += round;
        }
    }
    return true;
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
        if (solve())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}