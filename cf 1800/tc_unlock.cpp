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

int kmp(string &s)
{
    vector<int> pi(s.size());
    for (int i = 1; i < s.length(); i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[j] != s[i])
            j = pi[j - 1];
        if (s[j] == s[i])
            j++;
        pi[i] = j;
    }
    // cout << s << endl;
    // for (auto &val : pi)
    //     cout << val << " ";
    // cout << endl;
    return *max_element(pi.begin(), pi.end());
}

bool f(int sc, int par, vector<int> &dp, vector<int> &h, vector<int> v[], int an, int ap)
{
    // cout << sc << " " << an << " " << ap << endl;
    if (an < 0 || ap < 0)
        return true;
    bool ret = false;
    for (auto &c : v[sc])
    {
        if (c == par)
            continue;
        /*
          neg + pos = dp[c]
          neg - pos = h[c]
          2 * neg = dp[c] + h[c]
          */
        int neg = dp[c] + h[c];
        if (neg & 1)
        {
            ret = true;
        }
        neg >>= 1;
        int pos = dp[c] - neg;
        ret |= f(c, sc, dp, h, v, neg, pos);
        an -= neg, ap -= pos;
    }
    // cout << "   " << sc << " " << ret << endl;
    return ret;
}

int sum(int c, int par, vector<int> &a, vector<int> v[], vector<int> &dp)
{
    int ret = a[c];
    for (auto &child : v[c])
    {
        if (child == par)
            continue;
        ret += sum(child, c, a, v, dp);
    }
    return dp[c] = ret;
}

bool solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    vector<int> h(n + 1);
    vector<int> v[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    vector<int> dp(n + 1);
    sum(1, 0, a, v, dp);
    // for (int i = 1; i <= n; i++)
    //     cout << dp[i] << " ";
    // cout << endl;
    /*
    neg + pos = dp[c]
    neg - pos = h[c]
    2 * neg -= dp[c]+h[c]
    */
    bool fault = false;
    if ((dp[1] + h[1]) & 1)
        fault = true;
    int neg = (dp[1] + h[1]) / 2;
    int pos = dp[1] - neg;
    if (neg < 0 || pos < 0)
        fault = true;
    fault |= f(1, 0, dp, h, v, neg, pos);
    // cout << "fault " << fault << endl;
    return fault;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    if (t <= 2)
        while (t--)
        {
            if (!solve())
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    else
    {
        for (int i = 1; i <= t; i++)
        {
            int n, m;
            cin >> n >> m;
            vector<int> a(n + 1);
            vector<int> h(n + 1);
            vector<int> v[n + 1];
            for (int i = 1; i <= n; i++)
                cin >> a[i];
            for (int i = 1; i <= n; i++)
                cin >> h[i];
            if (i == 27)
            {
                cout << n << " " << m << endl;
                for (int i = 1; i <= n; i++)
                    cout << a[i] << " ";
                cout << endl;
                for (int i = 1; i <= n; i++)
                    cout << h[i] << " ";
                cout << endl;
            }
        }
    }
    return 0;
}