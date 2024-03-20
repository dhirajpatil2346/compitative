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
    vector<int> right = v;
    for (int i = n - 2; i >= 0; i--)
        right[i] ^= right[i + 1];
    int ans = *max_element(v.begin(), v.end());
    ans = max(ans, *max_element(right.begin(), right.end()));
    int c = right.back();
    for (int i = n - 2; i >= 0; i--)
    {
        c = right[i] ^ c;
        ans = max(c, ans);
    }
    cout << ans << endl;
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
1 2
2 1
4 1
8
*/