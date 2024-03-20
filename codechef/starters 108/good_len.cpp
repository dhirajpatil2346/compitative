#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n;
    cin >> n;
    vector<LL> a(n), b(n);
    for (auto &val : a)
        cin >> val;
    LL sum = accumulate(a.begin(), a.end(), 0ll);
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] == 1)
            b[i] = 2;
        else
            b[i] = 1;
        sum -= b[i];
    }
    if (sum == a.back())
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] - b[i] > 1)
            {
                sum--, b[i]++;
                break;
            }
        }
    }
    b.back() = sum;
    bool f = false;
    for (int i = 0; i < n; i++)
        if (a[i] == b[i])
        {
            f = true;
            break;
        }
    if (f || (accumulate(a.begin(), a.end(), 0ll) != accumulate(b.begin(), b.end(), 0ll)) || ((*min_element(b.begin(), b.end())) <= 0))
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
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