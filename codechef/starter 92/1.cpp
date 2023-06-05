#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n, k, l;
    cin >> n >> k >> l;
    priority_queue<int> q;
    while (n--)
    {
        int m, li;
        cin >> m >> li;
        if (li == l)
            q.push(m);
    }
    int s = 0;
    while (!q.empty() && k--)
    {
        s += q.top();
        q.pop();
    }
    if (s == 0)
        s = -1;
    cout << s << endl;
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