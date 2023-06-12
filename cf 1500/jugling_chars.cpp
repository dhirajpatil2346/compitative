#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    map<char, int> m;
    int N = n;
    while (N--)
    {
        string s;
        cin >> s;
        for (auto &val : s)
            m[val]++;
    }
    bool g = true;
    for (auto &val : m)
    {
        g &= (val.second % n == 0);
    }
    if (g)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
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