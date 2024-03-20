#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int long long
#define endl "\n"
#define Endl "\n"
const LL mod = 1e9 + 7;

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

const LL sz = 1e5 + 5;
vector<LL> primes(sz);
void sieve()
{
    for (int i = 0; i < primes.size(); i++)
        primes[i] = i;

    for (int i = 2; i * i <= sz; i++)
    {
        if (primes[i] == i)
            for (int j = i * i; j < sz; j += i)
                if (primes[j] == j)
                    primes[j] = i;
    }
}
long long oddProducts(int n, vector<int> &a)
{
    // Write your code here.
    long long ret = 0;
    long long maxi = 1;
    for (auto &val : a)
    {
        long long f = val;
        maxi *= f;
        cout << maxi << endl;
    }
    cout << maxi << endl;
    cout << "here" << endl;
    set<long long> squares;
    for (long long i = 1; (i * i) <= maxi; i++)
    {
        // cout << i << endl;
        squares.insert(i * i);
    }
    cout << "here" << endl;
    map<long long, vector<long long>> m;
    long long curr = 1;
    for (int i = 0; i < n; i++)
    {
        curr *= a[i];
        m[curr].push_back(i);
    }
    curr = 1;
    for (int i = 0; i <= n; i++)
    {
        cout << i << endl;
        // add curr to squares and check if it happens
        for (auto &val : squares)
        {
            long long z = val * curr;
            if (m.find(z) == m.end())
                continue;
            int ind = lower_bound(m[z].begin(), m[z].end(), i) - m[z].begin();
            if (ind == m[z].size())
                continue;
            ind = m[z].size() - ind;
            ret += ind;
        }
        if (i < n)
            curr *= a[i];
    }
    return ret;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    cout << oddProducts(n, v) << endl;
}
signed main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    sieve();
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}