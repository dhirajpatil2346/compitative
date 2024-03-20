#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define int long long
#define endl "\n"
#define Endl "\n"
const LL mod = 1e9 + 7;
vector<int> p_pow((int)(1e5 + 5), 1);
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> v(n);
    int tot = 0;
    for (int i = 0; i < n; i++)
    {
        int b = s[i] - 'a' + 1;
        v[i] = (b * p_pow[i]) % mod;
        tot = (tot + v[i]) % mod;
    }
    set<int> st;
    for (int i = 0; i <= n - 3; i++)
    {
        int curr = tot;
        string h = "";
        h.push_back(s[i + 1]);
        h.push_back(s[i + 2]);
        h.push_back(s[i]);
        for (int k = i; k <= i + 2; k++)
        {
            curr = (curr - v[k] + mod) % mod;
        }
        for (int k = i, j = 0; k <= i + 2; k++, j++)
        {
            int b = h[j] - 'a' + 1;
            b = (b * p_pow[k]) % mod;
            curr = (curr + b) % mod;
        }
        st.insert(curr);
    }
    cout << st.size() << endl;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 1; i < p_pow.size(); i++)
    {
        int ten = 31;
        p_pow[i] = (p_pow[i - 1] * ten) % mod;
    }
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}