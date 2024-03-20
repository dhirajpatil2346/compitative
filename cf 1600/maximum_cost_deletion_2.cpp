#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n, a, b, score = 0;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    if ((n * (a + b)) >= (n * a + b))
    {
        cout << n * (a + b) << endl;
        return;
    }
    stack<char> st;
    int i = 0;
    while (i < n)
    {
        if (st.empty() || st.top() != s[i])
            st.push(s[i++]);
        else
        {

            int cnt = 0;
            while (i < n && s[i] == st.top())
                i++, cnt++;
            cnt++;
            st.pop();
            score += (a * cnt + b);

            // cout << score << " " << a * cnt + b << endl;
            // cout << cnt << endl;
        }
    }
    string ans = "";
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    // cout << ans << endl;
    if (ans.size())
    {
        int cnt1 = 0, cnt2 = 0;
        for (auto &val : ans)
            if (val == '0')
                cnt1++;
            else
                cnt2++;
        int z = max(cnt1, cnt2) * a + b + min(cnt1, cnt2) * (a + b);
        int z1 = min(cnt1, cnt2) * a + b + max(cnt1, cnt2) * (a + b);
        int z2 = ans.size() * (a + b);
        score += max(z, max(z1, z2));
    }
    cout << score << endl;
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