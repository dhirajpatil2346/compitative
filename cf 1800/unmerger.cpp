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

// a.size() * b.size() * last

int dp[4002][4002][2];
vector<int> mx((int)1e4, -1);
int f(int a, int b, int last, vector<int> &v)
{
    int ind = a + b;
    // cout << a << " " << b << " " << last << endl;
    if (ind == v.size())
    {
        // cout << a + b << " " << last << endl;
        // cout << (a == b) << endl;
        return (a == b);
    }
    if (dp[a][b][last] != -1)
        return dp[a][b][last];
    int ret = 0;
    if (ind == 0)
    {
        ret = f(a + 1, b, 0, v);
    }
    else
    {
        if (mx[ind] != v[ind])
        {
            if (last == 0)
                ret = f(a + 1, b, 0, v);
            else
                ret = f(a, b + 1, 1, v);
            // cout << ret << endl;
        }
        else
        {
            // last < curr
            // cout << "  ind : " << ind << " " << v[ind - 1] << " " << v[ind] << endl;
            ret = (f(a + 1, b, 0, v));
            ret |= f(a, b + 1, 1, v);
        }
    }
    // if(ind==1)
    // cout << ind << " " << last << endl;
    return dp[a][b][last] = ret;
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n * 2; i++)
        for (int j = 0; j < n * 2; j++)
            for (int k = 0; k < 2; k++)
                dp[i][j][k] = -1;
    vector<int> v(2 * n);
    for (auto &val : v)
        cin >> val;
    mx[0] = v[0];
    for (int i = 1; i < n * 2; i++)
        mx[i] = max(mx[i - 1], v[i]);
    if (f(0, 0, 0, v))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i < 4e3 + 2; i++)
        for (int j = 0; j < 4e3 + 2; j++)
            for (int l = 0; l < 2; l++)
                dp[i][j][l] = -1;

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
3 2 8 4
6 1 5 7

1

6 1 3 8 2
7 4 5

2  4
3 1


1 2 3 4 5 6

1 4 5 6
2 3


3 4
1 2
1 2 3 4

3 1
4 2 
3 1 4 2

3 2
4 1
3 2 4 1
*/