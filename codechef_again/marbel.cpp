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
            for (LL j = i * i; j < sz; i += j)
                isp[j] = false;
    for (int i = 2; i < sz; i++)
        if (isp[i])
            primes.push_back(i);
}

void solve()
{
    LL chef, frd;
    cin >> chef >> frd;
    LL ans = 0;
    while (chef < frd)
    {
        ans++;
        chef++;
        frd--;
    }
    LL c1 = ans, c2 = ans;
    // change chef-- and frd++
    {
        LL c = chef, f = frd;
        bool got = false;
        while (c > 0 && f > 0)
        {
            if (c % f == 0)
            {
                got = true;
                break;
            }
            c--, f++, c1++;
        }
        // cout << c << " " << f << " " << got << endl;
        if (!got)
            c1 = 1e11;
    }
    // frd-- chef++
    // change chef-- and frd++
    {
        LL c = chef, f = frd;
        bool got = false;
        while (c > 0 && f > 0)
        {
            if (c % f == 0)
            {
                got = true;
                break;
            }
            else
                c++, f--, c2++;
        }
        if (!got)
            c2 = 1e11;
    }
    cout << min(c1, c2) << endl;
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