#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
}

class Solution
{
public:
    long long maximumSumOfHeights(vector<int> &maxHeights)
    {
        vector<long long> v;
        for (auto &val : maxHeights)
            v.push_back(val);
        int n = maxHeights.size();
        LL ans = 0;
        for (int i = 0; i < n; i++)
        {
            LL mini = v[i];
            LL curr = v[i];
            for (int j = i - 1; j >= 0; j--)
            {
                mini = min(v[j], mini);
                curr += mini;
            }
            mini = v[i];
            for (int j = i + 1; j < n; j++)
            {
                mini = min(v[j], mini);
                curr += mini;
            }
            cout << i << " " << curr << endl;
            ans = max(ans, curr);
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &val : v)
        cin >> val;
    Solution sc;
    cout << sc.maximumSumOfHeights(v) << endl;
    return 0;
}