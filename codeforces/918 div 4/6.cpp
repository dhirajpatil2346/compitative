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
    int n;
    cin >> n;
    vector<pair<int, int>> vp(n);
    for (auto &val : vp)
        cin >> val.first >> val.second;
    vector<int> end;
    map<int, vector<int>> m;
    for (auto &val : vp)
    {
        end.push_back(val.second);
    }
    LL ans = 0;
    for (LL i = 0; i < n; i++)
    {
        auto val = vp[i];
        int sp = val.first, ep = val.second;
        LL startpoint = lower_bound(end.begin(), end.end(), sp) - end.begin();
        startpoint = max(i + 1ll, startpoint);
        LL endpoint = upper_bound(end.begin(), end.end(), ep) - end.begin() - 1;
        startpoint = max(i + 1ll, endpoint);
        LL curr = endpoint - startpoint + 1;
        // now find points whose endpoints are far from you
        ans += curr;
    }
    cout << ans / 2ll << endl;
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