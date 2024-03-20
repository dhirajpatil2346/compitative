#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
vector<int> primes;
void sieve()
{
    int sz = 1e6 + 5;
    vector<bool> isp(sz, true);
    isp[0] = false, isp[1] = false;
    for (int i = 2; i * i <= sz; i++)
        if (isp[i])
            for (int j = i * i; j < sz; j += i)
                isp[j] = false;
    for (int i = 2; i < sz; i++)
        if (isp[i])
            primes.push_back(i);
}
void solve()
{
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