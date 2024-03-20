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

LL f(LL n, LL k)
{
    // initialise ans as 0
    LL ans = 0;
    // let ans has all bits in k till following don't comes
    // if n has bits but k don't then upgrade bit by (1+i) and make from  1 to i as zero and stop
    for (LL i = 63; i >= 0; i--)

        if ((n & (1LL << i)) && (!(k & (1LL << i))))
        {
            ans += (1LL << (i + 1));
            break;
        }
        else if (((n & (1LL << i)) && ((k & (1LL << i)))))
            ans |= (1LL << (i));
    // cout << ans << endl;
    if (((ans & n & k) != k))
        return -1;
    return ans;
}

void solve()
{
    LL n, k;
    cin >> n >> k;
    cout << f(n, k) << endl;
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