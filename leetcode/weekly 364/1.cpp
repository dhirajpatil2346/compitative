#include <bits/stdc++.h>
using namespace std;
#define LL long long
class Solution
{
public:
    long long maximumSumOfHeights(vector<int> &maxHeights)
    {
        vector<LL> v, cmf(maxHeights.size()), cmb(maxHeights.size());
        for (auto &val : maxHeights)
            v.push_back(val);
        int n = v.size();
        LL ans = 0;
        stack<pair<LL, LL>> st;
        for (LL i = 0; i < n; i++)
        {
            while (!st.empty() && st.top().first > v[i])
                st.pop();
            int last = -1;
            if (!st.empty())
                last = st.top().second;
    
            st.push({v[i], i});
        }
        while (!st.empty())
            st.pop();
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top().first > v[i])
                cmb[i] += v[i], st.pop();
            if (st.empty())
                cmb[i] += v[i];
            if (!st.empty())
                cmb[i] = cmb[st.top().second] + (st.top().second - i) * v[i];
            st.push({v[i], i});
        }
        for (auto &val : cmf)
            cout << val << " ";
        cout << endl;
        for (auto &val : cmb)
            cout << val << " ";
        cout << endl;
        for (int i = 0; i < n; i++)
            ans = max(ans, cmf[i] + cmb[i] - v[i]);
        return ans;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solution sc;
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    cout << sc.maximumSumOfHeights(v) << endl;
    return 0;
}