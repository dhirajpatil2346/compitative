#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    long long mod = 1e9 + 7;
    if (n == 1)
    {
        cout << m << endl;
    }
    else if (m == 1)
    {
        cout << 1 << endl;
    }
    else if (n % 2 == 0)
    {
        // (n / 2) can have m and one can have m - 1
        long long ans = 1;
        for (int i = 0; i < n / 2; i++)
        {
            ans = (ans * m) % mod;
        }
        long long one = 1;
        ans = (ans * (m - one)) % mod;
        cout << ans << endl;
    }
    else
    {
        // n / 2 + 1 will have m and one will have m - 1
        long long ans = 1;
        for (int i = 0; i < (n / 2) + 1; i++)
        {
            ans = (ans * m) % mod;
        }
        long long one = 1;
        ans = (ans * (m - one)) % mod;
        cout << ans << endl;
    }
    return 0;
}