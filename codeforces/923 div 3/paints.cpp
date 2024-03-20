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

int forw(int ind, vector<int> &v, vector<int> &dp)
{
    if (ind >= v.size())
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int ret = 1 + forw(ind + 1, v, dp);
    for (int i = 1; i < v[ind]; i++)
        ret = min(ret, 1 + forw(ind + i, v, dp));
    return dp[ind] = ret;
}

int back(int ind, vector<int> &v, vector<int> &dp)
{
    if (ind < 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int ret = 1 + back(ind - 1, v, dp);
    for (int i = 1; i < v[ind]; i++)
        ret = min(ret, 1 + back(ind - i, v, dp));

    return dp[ind] = ret;
}

int f(int ind, vector<int> &v, vector<int> &right, vector<int> &dp)
{
    if (ind >= v.size())
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int ret = 1e5;
    for (int i = 1; i <= v[ind]; i++)
        ret = min(ret, 1 + f(ind + i, v, right, dp));
    for (int i = ind + 1; i < v.size(); i++)
    {
        if ((i - v[i] + 1) <= ind)
            ret = min(ret, 1 + f(i + 1, v, right, dp));
    }
    int reach = right[ind];
    ret = min(ret, 1 + f(reach + 1, v, right, dp));
    // upto reach i can have paint
    for (int i = ind + 1; i < right[ind]; i++)
        reach = max(reach, i + v[i] - 1);

    ret = min(ret, 2 + f(reach + 1, v, right, dp));
    // cout << ind + 1 << " " << ret << endl;
    return dp[ind] = ret;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    vector<int> right(n);
    for (int i = 0; i < n; i++)
        right[i] = i;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j < v[i]; j++)
        {
            // cout << i - j << " " << right[i - j] << endl;
            if ((i - j) >= 0 && right[i - j] == (i - j))
                right[i - j] = i;
        }
    }
    // for (auto &val : right)
    //     cout << val << " ";
    // cout << endl;
    vector<int> dp(n, -1);
    cout << f(0, v, right, dp) << endl;
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

/*
4 1 2 5 3
12
34
5


*/