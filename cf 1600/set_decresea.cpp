#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n;
    cin >> n;
    LL k;
    cin >> k;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    sort(v.begin(), v.end());
    LL sum = accumulate(v.begin(), v.end(), 0ll);
    if (sum <= k)
    {
        cout << 0 << endl;
        return;
    }
    LL ini = min(v[0], k / n);
    LL ans = 0, csum = sum;
    ans += (v[0] - ini);
    csum -= (v[0] - ini);
    for (int i = n - 1; i >= 1 && csum > k; i--)
    {
        csum -= (v[i] - ini);
        ans++;
    }
    LL l = INT_MIN, r = ini;
    while (l <= r)
    {
        cout << l << " " << r << endl;
        bool f = false;
        if (l == r)
        {
            f = true;
        }
        ini = (l + r) / 2;
        LL moves = 0, csum = sum;
        moves += (v[0] - ini);
        csum -= (v[0] - ini);
        for (int i = n - 1; i >= 1 && csum > k; i--)
        {
            csum -= (v[i] - ini);
            moves++;
        }
        if (moves < ans)
        {
            r = ini - 1;
            ans = moves;
        }
        else
            l = ini + 1;
        if (f)
            break;
        // cout << ini << endl;
    }
    cout << ans << endl;
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
/*
0101
1000

00011
10011


*/