#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> v(n + 1);
    for (int i = 0; i < n; i++)
        v[i + 1] = s[i] - '0';
    vector<LL> ans;
    for (int i = 3; i <= n; i += 2)
    {
        int c1 = v[i - 2], c2 = v[i - 1];
        int c3 = v[i];
        LL z = 0;
        if ((c1 & c2) == c3)
            z++;
        if ((c1 | c2) == c3)
            z++;
        if ((c1 ^ c2) == c3)
            z++;
        ans.push_back(z);
    }
    const LL mod = 1e9 + 7;
    LL f = ans[0];
    for (int i = 1; i < ans.size(); i++)
        f = (f * ans[i]) % mod;
    cout << f << endl;
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