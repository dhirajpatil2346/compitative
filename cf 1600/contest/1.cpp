#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    k--;
    multiset<int> s;
    for (int i = 0; i < n - 1; i++)
        s.insert(abs(v[i] - v[i + 1]));
    while (k--)
    {
        s.erase(prev(s.end()));
    }
    int sum = 0;
    for (auto &val : s)
        sum += val;
    cout << sum << endl;
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
1 2 == 0
2 3 5 == 0

*/