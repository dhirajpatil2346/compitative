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

char C(int ind, string &s, vector<vector<int>> &v, vector<int> &start)
{
    int nind = upper_bound(start.begin(), start.end(), ind) - start.begin() - 1;
    if (nind == 0)
        return s[ind - 1];
    int diff = ind - v[nind][0];
    return C(v[nind][2] + diff, s, v, start);
}

void solve()
{
    int n, c, q;
    cin >> n >> c >> q;
    string s;
    cin >> s;
    vector<vector<int>> v(c + 1, vector<int>(4));
    v[0] = {1, n, 1, n};
    for (int i = 1; i <= c; i++)
    {
        cin >> v[i][2] >> v[i][3];
        int ele = v[i][3] - v[i][2] + 1;
        v[i][0] = v[i - 1][1] + 1, v[i][1] = v[i - 1][1] + ele;
    }
    vector<int> start;
    for (auto &val : v)
        start.push_back(val[0]);
    while (q--)
    {
        int ind;
        cin >> ind;
        cout << C(ind, s, v, start) << endl;
    }
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