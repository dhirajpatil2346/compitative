#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
int solve()
{
    int n, s;
    cin >> n >> s;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    int sum = 0;
    map<int, int> pos;
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        pos[sum] = i;
    }
    bool g = false;
    sum = 0;
    if (accumulate(v.begin(), v.end(), 0) < s)
        return -1;
    ans = n - 1 - pos[s];
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        if (pos.find(sum + s) == pos.end())
            break;
        ans = min(ans, i + 1 + n - 1 - pos[sum + s]);
        g = true;
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