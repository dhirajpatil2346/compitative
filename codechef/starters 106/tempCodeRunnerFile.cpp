#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

LL sz = 1e9 + 10;
const LL sq = sqrt(sz);
void solve()
{
    LL n;
    cin >> n;
    map<int, int> m;
    LL i = 2;
    while (i * i <= n)
    {
        if (n % i)
        {
        }
        else
        {
            while (n % i == 0)
            {
                m[i]++;
                n /= i;
            }
        }
        i++;
    }
    if (n > 1)
        m[n]++;
    int freq = 0;
    for (auto &val : m)
    {
        if (val.first == 2)
            continue;
        freq += val.second;
    }
    if (freq & 1)
        cout << "Alice" << endl;
    else
        cout << "Bob" << endl;
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