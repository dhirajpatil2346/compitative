#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n, k;
    cin >> n >> k;
    multiset<int> ms;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ms.insert(x);
    }
    while (k--)
    {
        int j;
        cin >> j;
        auto it = ms.upper_bound(j);
        if (it == ms.begin())
            cout << -1 << endl;
        else
        {
            cout << *(prev(it)) << endl;
            ms.erase(prev(it));
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}