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
    LL p = 31;
    vector<LL> p_pow((int)1e6 + 5);
    p_pow[0] = 1;
    for (int i = 1; i < 1e6 + 5; i++)
        p_pow[i] = (p_pow[i - 1] * p) % mod;
    string s;
    cin >> s;
    LL back = 0, front = 0, n = s.length();
    for (int i = 0, j = n - 1; i < n - 1; i++, j--)
    {
        front = (front + ((s[i] - 'a' + 1ll) * 1ll * p_pow[i])) % mod;
        back = (back * p) % mod;
        back = (back + (LL)(s[j] - 'a' + 1ll)) % mod;
        // cout << i << " " << front << " " << back << endl;
        // cout << (front == back) << endl;
        if (front == back)
            cout << i + 1 << " ";
    }
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int t;
    // cin >> t;
    // while (t--)
    // {
    solve();
    // }
    return 0;
}