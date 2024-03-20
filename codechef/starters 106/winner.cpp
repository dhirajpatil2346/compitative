#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

LL sz = 1e9 + 10;
const LL sq = sqrt(sz);
vector<LL> primes;
void sieve()
{
    vector<bool> isp(sq, true);
    isp[0] = false, isp[1] = false;
    for (LL i = 2; i * i <= sq; i++)
        if (isp[i])
            for (LL j = i * i; j < sq; j += i)
            {
                isp[j] = false;
            }
    for (int i = 2; i < sq; i++)
        if (isp[i])
            primes.push_back(i);
}
void solve()
{
    LL n;
    cin >> n;
    map<int, int> m;
    LL i = 0;
    if (n % 2 == 0 || n == 1)
        cout << "Bob" << endl;
    else
        cout << "Alice" << endl;
    while ((i < primes.size()) && ((primes[i] * primes[i]) <= n))
    {
        if (n % primes[i])
        {
        }
        else
        {
            while (n % primes[i] == 0)
            {
                m[primes[i]]++;
                n /= primes[i];
            }
        }
        i++;
    }
    if (n > 1)
        m[n]++;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();
    // for (int i = 0; i < 20; i++)
    //     cout << primes[i];
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*

10 = 2 * 5


20 = 2  * 2 * 5
15 = 3 * 5
12 = 2 * 2 * 3 or 10 = 2 * 5
9 = 3 * 3       or 5 = 5
6 = 3 * 2       or 5 = 0
3 = 3
0= 0
*/