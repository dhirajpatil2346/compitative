#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
const LL mod = 1e9 + 7;
const LL sz = 1e5 + 5;
LL dp[sz][3][2][2];
bool trv = false;
void sieve()
{
    for (int i = 0; i < sz; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                for (int l = 0; l < 2; l++)
                {
                    if (j == 2 && k == 1 && l == 1)
                    {
                        dp[i][j][k][l] = 1;
                    }
                    else
                        dp[i][j][k][l] = 0;
                }
            }
        }
    }
}
class Solution
{
public:
    LL f(int ind, int a, int b, int c, int n)
    {
        // if (a == 2 && b == 1 && c == 1)
            // cout << ind << " " << a << " " << b << " " << c << " " << endl;
        if (ind == n )
            return dp[ind][a][b][c];
        // a -> e
        // b -> l
        // c -> t
        LL ret = f(ind + 1, min(2, a + 1), b, c, n) % mod;
        ret = (ret + f(ind + 1, a, min(b + 1, 1), c, n)) % mod;
        ret = (ret + f(ind + 1, a, b, min(c + 1, 1), n)) % mod;
        ret = (ret + (23ll * f(ind + 1, a, b, c, n)) % mod) % mod;
        return ret;
    }
    int stringCount(int n)
    {
        if (!trv)
            sieve();
        LL ans =  f(0, 0, 0, 0, n);
        ans %= mod;
        return (int) ans;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    Solution sc;
    cout << sc.stringCount(n) << endl;
    return 0;
}