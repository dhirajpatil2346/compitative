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

bool check(int n, vector<int> &x)
{
    for (int i = n, need = 1; i >= 0; i--, need++)
        if (x[i] < need)
            return false;
    return true;
}
class Solution
{
public:
    long long minimumMoves(vector<int> &nums, int k, int maxChanges)
    {
        int n = nums.size();
        vector<int> d(n);
        for (int i = 2; i < n; i++)
            d[i] += nums[i - 1];
        vector<int> v;
        for (int i = 0; i < n; i++)
            if (v[i] == 1)
                v.push_back(i);
        vector<int> f = v, b = v;
        for (int i = v.size() - 2; i >= 0; i--)
            f[i] += f[i + 1];
        for (int i = 1; i < v.size(); i++)
            b[i] += b[i - 1];
        for (int i = 0; i < n; i++)
        {
            int m = 0;
            int c = 0;
            c += nums[i];
            if (c == k)
                return m;
            if (i > 0)
                c += nums[i - 1];
            if (c == k)
                return m;
            if (i < (n - 1))
                c += nums[i + 1];
            if (c == k)
                return m;
            if ((k - c) <= maxChanges)
                m += (2 * (k - c)), c += (2 * (k - c));
            else
                m += (2 * maxChanges), c += maxChanges;
            if (c == k)
                return m;
            int left = k - c, cost = 1e9, lefts = d[i];
            lefts = min(left, lefts);
            int l = 1, r = lefts;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                // chose these much from leftside
                int il = prev(lower_bound(v.begin(), v.end(), i - 1)) - v.begin();
                // containing this you have to remove
                int ir = upper_bound(v.begin(), v.end(), i + 1) - v.begin();
            }
        }
    }
};
void solve()
{
    Solution sc;
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    cout << sc.minimumMoves(v, k, m) << Endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}