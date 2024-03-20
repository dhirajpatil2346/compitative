#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
int solve()
{
    int ans = 0;
    int n;
    cin >> n;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        m[a]++;
    }
    for (auto &val : m)
    {
        int others = m.size() - 1;
        ans = max(ans, min(others, val.second));
        ans = max(ans, min(others + 1, val.second - 1));
    }
    return ans;
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
        cout << solve() << endl;
    }
    return 0;
}