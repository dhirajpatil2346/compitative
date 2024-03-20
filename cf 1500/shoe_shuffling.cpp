#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    map<int, queue<int>> m;
    for (int i = 0; i < n; i++)
        m[v[i]].push(i + 1);
    for (auto &val : m)
    {
        if (val.second.size() == 1)
        {
            cout << -1 << endl;
            return;
        }
        int s = val.second.front();
        val.second.pop();
        val.second.push(s);
    }
    for (int i = 0; i < n; i++)
    {
        cout << m[v[i]].front() << " ";
        m[v[i]].pop();
    }
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