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

bool solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    // cout << 'h' << endl;
    // cout << n << " " << k << " " << s << endl;
    for (int i = 0; i < k; i++)
    {
        // cout << i << " ";
        set<char> c;
        for (int j = i; j < n; j += k)
            c.insert(s[j]);
        if (c.size() == 1)
            continue;
        if (c.find('1') != c.end() && c.find('0') != c.end())
            return false;
        c.erase('?');
        char ch = *c.begin();
        for (int j = i; j < n; j += k)
            s[j] = ch;
    }
    // cout << 'h' << endl;
    int o = 0, z = 0;
    for (int i = 0; i < k; i++)
        if (s[i] == '0')
            z++;
        else if (s[i] == '1')
            o++;
    if (z > k / 2 || o > k / 2)
        return false;
    // cout << 'h' << endl;
    for (int i = k, j = 0; i < n; i++, j++)
    {
        if (s[j] == '1')
            o--;
        if (s[j] == '0')
            z--;
        if (s[i] == '0')
            z++;
        else if (s[i] == '1')
            o++;
        if (z > k / 2 || o > k / 2)
            return false;
    }
    return true;
}
signed main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
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