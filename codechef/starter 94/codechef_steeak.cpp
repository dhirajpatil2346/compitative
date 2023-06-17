#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<int> v1(n), v2(n);
    for (auto &val : v1)
        cin >> val;
    for (auto &val : v2)
        cin >> val;
    int ans = 0;
    int i = 0;
    while (i < n)
    {
        if (v1[i] == 0)
        {
            i++;
            continue;
        }
        int j = 0;
        while (i < n && v1[i] != 0)
        {
            j++, i++;
        }
        ans = max(ans, j);
    }
    int ans2 = 0;
    i = 0;
    while (i < n)
    {
        if (v2[i] == 0)
        {
            i++;
            continue;
        }
        int j = 0;
        while (i < n && v2[i] != 0)
        {
            j++, i++;
        }
        ans2 = max(ans2, j);
    }
    if (ans == ans2)
        cout << "Draw" << endl;
    else if (ans > ans2)
        cout << "Om" << endl;
    else
        cout << "Addy" << endl;
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

13 -> 1101
7  -> 0111

*/