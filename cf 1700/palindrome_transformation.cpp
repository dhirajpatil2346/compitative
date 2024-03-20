#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int long long
#define endl "\n"
#define Endl "\n"
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

int deal(int pos, vector<int> &left)
{
    if (left.size() == 0)
        return 0;
    // go right corner and go left corner
    int rightdist = 0, leftdist = 0;
    if (pos < left.back())
        rightdist = left.back() - pos;
    if (left.front() < pos)
        leftdist = pos - left.front();
    // go left corner and go right corner
    return min(2 * rightdist + leftdist, 2 * leftdist + rightdist);
}
void solve()
{
    int n, k;
    cin >> n >> k;
    k--;
    if (k > (n - k - 1))
        k = n - k - 1;
    string s;
    cin >> s;
    vector<int> left;
    int ans = 0;
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] == s[n - i - 1])
            continue;
        ans += min(abs(s[i] - s[n - i - 1]), (26 - abs(s[i] - s[n - i - 1])) % 26);
        left.push_back(i);
    }
    cout << ans + deal(k, left) << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}