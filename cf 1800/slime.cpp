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
vector<LL> primes, ans1;
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

void solve()
{
    ans1.clear();
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    vector<int> V = v;
    set<int> eats_right = {-1, n}, eats_left = {-1, n};
    for (int i = 0; i < n - 1; i++)
        if (v[i] != v[i + 1])
            eats_right.insert(i);
    for (int i = n - 1; i > 0; i--)
        if (v[i] != v[i - 1])
            eats_left.insert(i);
    for (int i = 1; i < n; i++)
        v[i] += v[i - 1];
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && V[i] < V[i - 1])
            ans1.push_back(1);
        else if ((i + 1) < n && V[i] < V[i + 1])
            ans1.push_back(1);
        else
        {
            int left = -1, right = -1;
            int L = 0, R = *prev(eats_right.lower_bound(i - 1));
            while (L <= R)
            {
                int m = (L + R) / 2;
                int sum = 0;
                if ((i - 1) >= 0)
                    sum += v[i - 1];
                if (m > 0)
                    sum -= v[m - 1];
                m = (L + R) / 2;
                if (sum > V[i])
                {
                    left = m;
                    L = m + 1;
                }
                else
                    R = m - 1;
            }
            L = *eats_left.upper_bound(i + 1), R = n - 1;
            while (L <= R)
            {
                int m = (L + R) / 2, sum = 0;
                sum += v[m];
                sum -= v[i];
                m = (L + R) / 2;
                if (sum > V[i])
                {
                    right = m;
                    R = m - 1;
                }
                else
                    L = m + 1;
            }
            int ans = 1e9;
            if (left != -1)
                ans = min(ans, i - left);
            if (right != -1)
                ans = min(ans, right - i);
            if (ans == 1e9)
                ans = -1;
            ans1.push_back(ans);
        }
    }
    for (auto &val : ans1)
        cout << val << " ";
    cout << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}