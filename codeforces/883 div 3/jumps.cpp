#include <bits/stdc++.h>
using namespace std;
#define LL long long
class Solution
{
public:
    int mini(int ind, int par, vector<int> v1, vector<int> &v2, vector<vector<int>> &dp)
    {
        if (ind >= v1.size())
            return 0;
        if (dp[ind][par] != -1)
            return dp[ind][par];
        int ret = 0;
        if (par == 0)
        {
            if (v1[ind] >= v1[ind - 1])
                ret = max(ret, 1 + mini(ind + 1, 0, v1, v2, dp));
            if (v2[ind] >= v1[ind - 1])
                ret = max(ret, 1 + mini(ind + 1, 1, v1, v2, dp));
        }
        else
        {
            if (v1[ind] >= v2[ind - 1])
                ret = max(ret, 1 + mini(ind + 1, 0, v1, v2, dp));
            if (v2[ind] >= v2[ind - 1])
                ret = max(ret, 1 + mini(ind + 1, 1, v1, v2, dp));
        }
        return dp[ind][par] = ret;
    }
    int maxNonDecreasingLength(vector<int> &v1, vector<int> &v2)
    {
        if (v1.size() == 1)
            return 1;
        vector<vector<int>> dp(v1.size(), vector<int>(2, -1));
        int mx = 0, n = v1.size();
        for (int i = 1; i < n; i++)
        {
            mx = max(mx, 1 + max(mini(i + 1, 0, v1, v2, dp), mini(i + 1, 1, v1, v2, dp)));
        }
        return mx;
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
    vector<int> nums1(n), nums2(n);
    for (auto &val : nums1)
        cin >> val;
    for (auto &val : nums2)
        cin >> val;
    cout << sc.maxNonDecreasingLength(nums1, nums2) << endl;
    return 0;
}