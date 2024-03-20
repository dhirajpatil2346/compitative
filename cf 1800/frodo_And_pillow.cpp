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

LL solve()
{
    LL n, M, k;
    cin >> n >> M >> k;
    LL ans = 1;
    LL L = 1, R = M;
    while (L <= R)
    {
        LL m = (L + R) / 2ll;
        LL left = k;
        LL right = n - k;
        LL left_one = 0, right_one = 0;
        left_one = max(left_one, left - k), right_one = max(right_one, right - (k - 1ll));
        left -= left_one, right -= right_one;
        LL used = left_one + right_one;
        used += ((left * (2ll * k + (left - 1ll) * (-1ll))) / 2ll);
        used += ((right * (2ll * (k - 1ll) + (right - 1ll) * (-1ll))) / 2ll);
        cout << m << " " << used << endl;
        if (used <= M)
        {
            ans = m;
            L = m + 1ll;
        }
        else
            R = m - 1ll;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        cout << solve() << endl;
    }
    return 0;
}