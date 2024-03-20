#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int long long
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

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.first != b.first)
        return a.first > b.first;
    return a.second < b.second;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> v(m);
    for (auto &val : v)
        cin >> val;
    for (int i = 0; i < m; i++)
    {
        if (i + v[i] > n)
        {
            cout << -1 << endl;
            return;
        }
    }
    vector<int> pos(m);
    for (int i = 0; i < m; i++)
        pos[i] = i + 1;
    int next = n + 1;
    for (int i = m - 1; i >= 0; i--)
    {
        pos[i] = max(pos[i], next - v[i]);
        next = pos[i];
    }
    if (next != 1)
    {
        cout << -1 << endl;
    }
    else
    {
        for (auto &val : pos)
            cout << val << " ";
        cout << endl;
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}