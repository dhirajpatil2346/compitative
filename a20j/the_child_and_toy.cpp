#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    int ans = 0;
    while (k--)
    {
        int x, y;
        cin >> x >> y;
        ans += min(v[x], v[y]);
    }
    cout << ans << endl;
    return 0;
}