#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    sort(v.begin(), v.end());
    for (int i = 0; i <= n; i++)
    {
        int c = 0;
        for (int j = 0; j < n; j++)
        {
            if (v[j] >i)
                c++;
        }
        if (c == i)
        {
            cout << c << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}