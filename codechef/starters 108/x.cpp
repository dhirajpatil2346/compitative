#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const LL mod = 1e9 + 7;
class Solution
{
public:
    int maximumXorProduct(long long a, long long b, int n)
    {
        if (n == 0)
        {
            LL x = 0;
            a ^= x;
            b ^= x;
            a %= mod, b %= mod;
            a = (a * b) % mod;
            return (int)a;
        }
        if (a < b)
            swap(a, b);
        LL bit = 63;
        while (bit >= 0)
        {
            if ((a & (1ll << bit)) && (!(b & (1ll << bit))))
            {
                break;
            }
            bit--;
        }
        string s(n, '0');
        int msb = -1;
        bool ua = false, ub = false;
        // cout << "bit " << bit << endl;
        if (bit >= n)
        {
            ua = true;
        }
        for (LL i = n - 1, j = 0; i >= 0; i--, j++)
        {
            if ((!(a & (1ll << i))) && (!(b & (1ll << i))))
            {
                s[j] = '1';
                continue;
            }
            if ((a & (1ll << i)) && (b & (1ll << i)))
                continue;
            if (ua == false)
            {
                // cout << "ua is false " << i << endl;
                if (a & (1ll << i))
                {
                    // a has that bit
                    // no modify to s
                }
                else
                {
                    s[j] = '1';
                }
                ua = true;
            }
            else
            {
                // ub is false
                if ((b & (1ll << i)))
                {
                    // don't mod
                }
                else
                {
                    s[j] = '1';
                }
            }
        }
        LL x = 0;
        for (LL i = n - 1, j = 0; i >= 0; i--, j++)
        {
            if (s[j] == '1')
                x += (1l << i);
        }
        // cout << "x " << x << endl;
        a ^= x;
        b ^= x;
        a %= mod, b %= mod;
        a = (a * b) % mod;
        return (int)a;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solution sc;
    int t;
    cin >> t;
    while (t--)
    {
        LL a, b, n;
        cin >> a >> b >> n;
        cout << sc.maximumXorProduct(a, b, n) << endl;
    }
    return 0;
}