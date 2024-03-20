#include <bits/stdc++.h>
using namespace std;
#define LL long long

class Solution
{
public:
    void build(vector<int> &a, int ind, int l, int r, vector<int> &v)
    {
        if (r < l)
            return;
        if (l == r)
        {
            a[ind] = v[l];
            return;
            // return a[ind];
        }
        int mid = (l + r) / 2;
        build(a, ind * 2, l, mid, v);
        build(a, ind * 2 + 1, mid + 1, r, v);
        a[ind] = max(a[ind * 2], a[ind * 2 + 1]);
    }

    int geT(vector<int> &a, int ind, int l, int r, int L, int R)
    {
        if (r < l)
            return 0;
        if (L > r || R < l)
            return 0;
        if (L >= l && r <= R)
            return a[ind];
        int mid = (l + r) / 2;
        return max(geT(a, ind * 2, l, mid, L, R), geT(a, ind * 2 + 1, mid + 1, r, L, R));
    }

    vector<int> leftmostBuildingQueries(vector<int> &heights, vector<vector<int>> &queries)
    {
        int n = heights.size();
        vector<int> a(4 * n);
        build(a, 1, 0, n - 1, heights);
        vector<int> ret;
        for (auto &val : queries)
        {
            int ans = -1;
            int L = max(val[0], val[1]), R = n - 1;
            int sv = max(heights[val[0]], heights[val[1]]);
            while (L <= R)
            {
                int mid = (L + R) / 2;
                int g = geT(a, 1, 0, n - 1, L, mid);
                if (g >= sv)
                {
                    ans = mid;
                    R = mid - 1;
                }
                else
                    L = mid + 1;
            }
            ret.push_back(ans);
        }
        return ret;
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Solution sc;
    return 0;
}