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

bool match(string a, string t)
{
    int n = t.length();
    for (int i = 0; i < n; i++)
    {
        if (t[i] >= 'A' && t[i] <= 'Z')
        {
            char low = t[i] - 'A' + 'a';
            if (low == a[i])
                return false;
        }
        else if (a[i] != t[i])
            return false;
    }
    return true;
}

bool solve()
{
    LL n;
    cin >> n;
    vector<string> v(3);
    for (auto &val : v)
        cin >> val;
    for (int i = 0; i < n; i++)
    {
        if (v[0][i] == v[2][i] || v[1][i] == v[2][i])
            continue;
        if (v[0][i] == v[1][i])
            return true;
        set<char> s;
        for (auto &val : v)
            s.insert(val[i]);
        if (s.size() == 3)
            return true;
    }
    return false;
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
        if (solve())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
/*
 */