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
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    int prev = 0, mn = v[0];
    v[0] = 0;
    for (int i = 1; i < n; i++)
    {
        mn = min(v[i], mn);
        // cout << i << endl;
        // for (auto &val : v)
        //     cout << val << " ";
        // cout << endl;
        if (v[i - 1] > v[i])
            return false;
        /*
            curr>=prev
            curr-mn >= prev
            curr - prev >= mn
        */
        mn = min(mn, v[i] - v[i - 1]);
        v[i] -= mn;
        v[i] = max(v[i], v[i - 1]);
    }
    // for (auto &val : v)
    //     cout << val << " ";
    // cout << endl;
    mn = v.back();
    for (int i = n - 1; i >= 0; i--)
    {
        mn = min(mn, v[i]);
        v[i] -= mn;
    }
    return *max_element(v.begin(), v.end()) == 0;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    if (t)
        while (t--)
        {
            if (solve())
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    else
    {
        for (int i = 1; i < t + 1; i++)
        {
            int n;
            cin >> n;
            vector<int> v(n);
            for (auto &val : v)
                cin >> val;
            if (i == 59)
            {
                cout << n << endl;
                for (auto &val : v)
                    cout << val << " ";
                cout << endl;
            }
        }
    }
    return 0;
}
/*
10
13 20 13 10 13 15 10 15 15 14


5 4 3 2 1 10 1 2 3 4 5


5
11 7 9 6 8

0 0 0 0 0
5 1 0 0

11 6 7 10 9 9 8
0 0 1 4 4 4 4

mb <= v[i]-mn
*/