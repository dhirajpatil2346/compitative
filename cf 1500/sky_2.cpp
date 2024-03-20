#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<LL> v(n), dp(n), dp1(n);
    for (auto &val : v)
        cin >> val;
    stack<pair<LL, LL>> s;
    vector<LL> sum = v;
    for (int i = 1; i < n; i++)
        sum[i] += sum[i - 1];
    stack<pair<LL, LL>> st;
    for (LL i = 0; i < n; i++)
    {
        while (!st.empty() && st.top().first >= v[i])
            st.pop();
        LL csum = sum[i], ele = i + 1;
        if (!st.empty())
        {
            dp[i] = dp[st.top().second];
            csum -= sum[st.top().second];
            ele -= (st.top().second + 1);
        }
        csum -= (ele * v[i]);
        dp[i] += csum;
        st.push({v[i], i});
    }
    // worked fine till

    while (!st.empty())
        st.pop();
    for (auto &val : sum)
        val = 0;
    sum = v;
    for (int i = n - 2; i >= 0; i--)
        sum[i] += sum[i + 1];
    for (LL i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top().first >= v[i])
            st.pop();
        LL csum = sum[i], ele = (-1ll) * (i + 1);
        if (!st.empty())
        {
            dp1[i] += dp1[st.top().second];
            csum -= sum[st.top().second];
            ele += (st.top().second + 1);
        }
        else
            ele += n + 1;
        csum -= (ele * v[i]);
        dp1[i] += csum;
        st.push({v[i], i});
    }
    for (int i = 0; i < n; i++)
        dp[i] += dp1[i];
    long long pos = min_element(dp.begin(), dp.end()) - dp.begin();
    long long mn = v[pos];
    for (long long i = pos - 1; i >= 0; i--)
    {
        mn = min(mn, v[i]);
        v[i] = mn;
    }
    mn = v[pos];
    for (long long i = pos + 1; i < n; i++)
    {
        mn = min(mn, v[i]);
        v[i] = mn;
    }
    for (auto &val : v)
        cout << val << " ";
    cout << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}