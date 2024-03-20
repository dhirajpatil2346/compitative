#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (auto &val : v)
        cin >> val;
    vector<long long> dp(n);
    for (long long i = 0; i < n; i++)
    {
        long long mn = v[i];
        for (long long j = i - 1; j >= 0; j--)
        {
            mn = min(mn, v[j]);
            dp[i] += abs(v[j] - mn);
        }
        mn = v[i];
        for (long long j = i + 1; j < n; j++)
        {
            mn = min(mn, v[j]);
            dp[i] += abs(mn - v[j]);
        }
    }
    long long pos = min_element(dp.begin(), dp.end()) - dp.begin();
    long long mn = v[pos];
    for (long long i = pos - 1; i >= 0; i--)
    {
        mn = min(mn, v[i]);
        v[i] = mn;
    }
    mn = v[pos];
    for (long long i = pos + 1; i < n; i++)
    {
        mn = min(mn, v[i]);
        v[i] = mn;
    }
    for (auto &val : v)
        cout << val << " ";
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long t;
    solve();
    return 0;
}