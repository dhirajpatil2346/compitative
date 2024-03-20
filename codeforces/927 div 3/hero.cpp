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

int g(string &h)
{
    int num = 0;
    for (auto &val : h)
    {
        num *= 10ll;
        int c = val - '0';
        num += c;
    }
    return num;
}

void solve()
{
    char ch;
    int n, carry = 0;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
    {
        cin >> ch;
        val = ch - '0';
    }
    for (int i = 1; i < n; i++)
        v[i] += v[i - 1];
    string ans = "";
    while (v.size())
    {
        v.back() += carry;
        string z = to_string(v.back());
        ans.push_back(z.back());
        z.pop_back();
        carry = g(z);
        v.pop_back();
    }
    if (carry > 0)
    {
        ans.push_back(char(carry + '0'));
    }
    while (ans.size() && ans.back() == '0')
        ans.pop_back();

    reverse(ans.begin(), ans.end());
    if (ans.size() == 0)
        ans.push_back('0');
    cout << ans << endl;
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