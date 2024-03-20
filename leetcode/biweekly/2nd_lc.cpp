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
class Solution
{
public:
    long long findMaximumNumber(long long k, int x)
    {
        int lim = 63;
        vector<LL> v(64);
        for (LL i = x - 1; i < 64; i++)
        {
            LL bits_avail = (i + 1);
            for (LL m = 1; m < 64; m++)
            {
                if (m * x > bits_avail)
                    break;
                LL to_use = m * x;
                LL p = 1;
                for (LL o = bits_avail; o > to_use; o--)
                {
                    p *= o;
                }
                v[i] += p * to_use;
            }
            // cout << i << " " << v[i] << endl;
            if (v[i] <= k)
            {
                lim = i;
            }
            if (v[i] > k)
                break;
        }
        for (auto &val : v)
            cout << val << " ";
        cout << endl;
        LL prev = 0, curr = 0;
        for (int i = lim; i >= 0; i--)
        {
            if (i % 2 == 0)
                continue;
            if (prev + v[i] < k)
            {
                prev += v[i];
                curr += (1LL << i);
            }
        }
        return curr;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solution sc;
    LL n, k;
    cin >> n >> k;
    cout << sc.findMaximumNumber(n, k) << endl;
    return 0;
}