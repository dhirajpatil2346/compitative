#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string r = "RGB", g = "GBR", b = "BRG";
    vector<int> rarray(n), garray(n), barray(n);
    // for r array
    for (int i = 0; i < n; i++)
        rarray[i] = (s[i] != r[i % 3]);

    // for g array
    for (int i = 0; i < n; i++)
        garray[i] = (s[i] != g[i % 3]);

    // for b array
    for (int i = 0; i < n; i++)
        barray[i] = (s[i] != b[i % 3]);

    for (int i = 1; i < n; i++)
    {
        barray[i] += barray[i - 1];
        garray[i] += garray[i - 1];
        rarray[i] += rarray[i - 1];
    }
    int ans = rarray[k - 1];
    ans = min(ans, garray[k - 1]);
    ans = min(ans, barray[k - 1]);
    for (int i = k; i < n; i++)
    {
        ans = min(ans, garray[i] - garray[i - k]);
        ans = min(ans, barray[i] - barray[i - k]);
        ans = min(ans, rarray[i] - rarray[i - k]);
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