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

int f(int ind, int sr, int sc, vector<vector<vector<LL>>> &dp, string &s)
{
    if (sr < 0 || sc < 0 || sr >= 7 || sc >= 7)
        return 0;
    if (ind == s.size())
        return (sr == 6 && sc == 0);
    if (dp[ind][sr][sc] != -1)
        return dp[ind][sr][sc];
    LL ret = 0;
    if (s[ind] == '?')
    {
        ret += f(ind + 1, sr + 1, sc, dp, s);
        ret += f(ind + 1, sr - 1, sc, dp, s);
        ret += f(ind + 1, sr, sc + 1, dp, s);
        ret += f(ind + 1, sr, sc - 1, dp, s);
    }
    else
    {
        if (s[ind] == 'R')
            ret += f(ind + 1, sr, sc + 1, dp, s);
        if (s[ind] == 'L')
            ret += f(ind + 1, sr, sc - 1, dp, s);
        if (s[ind] == 'U')
            ret += f(ind + 1, sr - 1, sc, dp, s);
        if (s[ind] == 'D')
            ret += f(ind + 1, sr + 1, sc, dp, s);
    }
    return dp[ind][sr][sc] = ret;
}
void solve()
{
    string s;
    cin >> s;
    vector<vector<vector<LL>>> dp(s.length(), vector<vector<LL>>(7, vector<LL>(7, -1)));
    cout << f(0, 0, 0, dp, s) << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}