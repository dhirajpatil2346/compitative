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
    string s;
    cin >> s;
    map<char, int> m;
    for (auto &val : s)
        m[val]++;
    string s1 = "", s2 = "";
    for (auto &val : m)
    {
        if (val.second % 2)
            continue;
        LL f1 = val.second / 2;
        LL f2 = val.second - f1;
        while (f1--)
            s1.push_back(val.first);
        while (f2--)
            s2.push_back(val.first);
    }
    for (auto &val : m)
    {
        if (val.second % 2 == 0)
            continue;
        LL f1 = val.second / 2;
        LL f2 = val.second - f1;
        while (f1--)
            s1.push_back(val.first);
        while (f2--)
            s2.push_back(val.first);
    }
    reverse(s2.begin(), s2.end());
    s1 += s2;
    s2 = s1;
    reverse(s2.begin(), s2.end());
    if (s1 != s2)
        s1 = "NO SOLUTION";
    cout << s1 << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}