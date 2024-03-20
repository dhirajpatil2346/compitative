#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    int i = 0, j = 1;
    LL op = 0;
    while (i < n && j < n)
    {
        if (i == j)
        {
            j++;
            continue;
        }
        if (v[j])
        {
            j++;
            continue;
        }
        if (v[i] == 0)
        {
            i++;
            continue;
        }
        v[i]--, v[j]++;
        op++;
    }
    for (int i = 0; i < n - 1; i++)
        op += v[i];
    cout << op << endl;
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