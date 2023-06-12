#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<int> v(1e8);
    for (auto &val : v)
        cin >> val;
    set<int> s, got;
    for (auto &val : v)
        s.insert(val);

    for (int i = 2; i <= n; i++)
    {
        int sum = 0;
        for (int j = 0; j < i; j++)
            sum += v[j];
        for (int j = i, m = 0; j < n; j++, m++)
        {
            sum -= v[m];
            sum += v[j];
            if (s.find(sum) != s.end())
                got.insert(sum);
        }
    }
    int a = 0;
    for (auto &val : v)
        if (got.find(val) != got.end())
            a++;
    cout << endl;
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