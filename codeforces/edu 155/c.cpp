#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
const int N = 2e5 + 1;
const LL mod = 998244353;
vector<LL> fact(N);
void sieve()
{
    fact[0] = 1;
    for (LL i = 1; i < fact.size(); i++)
        fact[i] = (i * fact[i - 1]) % mod;
}

LL bin(LL a, LL p)
{
    if (p == 0)
        return 1;
    LL res = bin(a, p / 2ll);
    res = (res * res) % mod;
    if (p & 1ll)
    {
        res = (res * a) % mod;
    }
    return res % mod;
}

LL mmi(LL x)
{
    return bin(x, mod - 2);
}

void solve()
{
    string s;
    cin >> s;
    bool g = false;
    LL n = s.length();
    LL i = 0;
    while (i < n)
    {
        int c = 0;
        char key = s[i];
        while (i < n && s[i] == key)
            i++, c++;
        if (c > 1)
        {
            g = true;
            break;
        }
    }
    if (!g)
    {
        cout << "0 1" << endl;
        return;
    }
    i = 0;
    LL a = 0, ans = 1, p = 0;
    vector<LL> fin;
    while (i < n)
    {
        char key = s[i];
        LL c = 0;
        while (i < n && s[i] == key)
            i++, c++;
        a += (c - 1ll);
        if (c > 1)
        {
            fin.push_back(c);
        }
    }
    LL cm = accumulate(fin.begin(), fin.end(), 0ll);
    // cout << cm << endl;
    ans = 1;
    while (fin.size())
    {
        LL q = fin.back();
        while (--q)
        {
            ans = (ans * cm) % mod;
            // cout<<cm<<" "<<ans<<endl;
            cm--;
        }
        cm--;
        fin.pop_back();
    }
    // ans = bin(cm, (LL)(fin.size()));
    cout << a << " " << ans << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();
    // for (int i = 0; i < 10; i++)
    //     cout << i << " " << fact[i] << endl;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
1234 -->
4digs
1
2
*/
/*
100100
24,34,52,42,43
*/