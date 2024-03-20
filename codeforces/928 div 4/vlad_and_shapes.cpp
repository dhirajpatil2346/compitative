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
    int n;
    cin >> n;
    vector<string> v(n);
    for (auto &val : v)
        cin >> val;
    int ones = 0;
    for (auto &val : v)
        ones += count(val.begin(), val.end(), '1');
    int sq = sqrt(ones);
    if ((sq * sq) != ones || ones == 0)
    {
        cout << "TRIANGLE" << endl;
        return;
    }
    // cout << ones << endl;
    int start = 0;
    for (auto &val : v)
    {
        if (count(val.begin(), val.end(), '1') != 0)
        {
            start = count(val.begin(), val.end(), '1');
            break;
        }
    }
    // cout << 1 << endl;
    // cout << start << endl;
    bool folt = false;
    for (auto &val : v)
    {
        if (count(val.begin(), val.end(), '1') == 0)
            continue;
        if (count(val.begin(), val.end(), '1') != start || count(val.begin(), val.end(), '1') != sq)
        {
            cout << "TRIANGLE" << endl;
            return;
        }
    }
    set<int> sc, ec;
    for (auto &val : v)
    {
        if (count(val.begin(), val.end(), '1') == 0)
            continue;
        for (int i = 0; i < n; i++)
        {
            if (val[i] == '1')
            {
                sc.insert(i);
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (val[i] == '1')
            {
                ec.insert(i);
                break;
            }
        }
    }
    if (ec.size() > 1 || sc.size() > 1)
    {
        cout << "TRIANGLE" << endl;
        return;
    }
    cout << "SQUARE" << endl;
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