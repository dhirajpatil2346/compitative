#include <bits/stdc++.h>
using namespace std;
#define LL long long

int mini(int ind, vector<int> &v, int l, int r, int L, int R)
{
    if (r < l)
        return 1e8;
    if (r == l)
        return v[ind];
    if (r < L)
        return 1e8;
    if (l >= L && r <= R)
        return v[ind];
    if (l > R)
        return 1e8;
    // L R is the block to find in l r
    int mid = (l + r) / 2;
    return min(mini(ind * 2, v, l, mid, L, R), mini(ind * 2 + 1, v, mid + 1, r, L, R));
}
void build(int ind, vector<int> &v, int l, int r, vector<int> &ref)
{
    if (l > r)
        return;
    if (l == r)
    {
        v[ind] = ref[l];
        return;
    }
    build(ind * 2, v, l, (l + r) / 2, ref);
    build(ind * 2 + 1, v, (l + r) / 2 + 1, r, ref);
    v[ind] = min(v[ind * 2], v[ind * 2 + 1]);
}

class Solution
{
public:
    int maxGoodLength(vector<vector<int>> &v)
    {
        int n = v.size(), m = v[0].size();
        vector<vector<int>> row(n, vector<int>(4 * m, 1e8)), col(n, vector<int>(4 * m, 1e8));
        vector<vector<int>> columns(m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                columns[j].push_back(v[i][j]);
        for (int i = 0; i < row.size(); i++)
            build(1, row[i], 0, m - 1, v[i]);
        int l = 1, r = min(n, m);
        cout << endl;
        int ans = 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            bool g = false;
            for (int c = 0; c < m && g == false; c++)
            {

                if (c + l - 1 == m)
                    break;
                vector<int> minis;
                for (int r = 0; r < n && g == false; r++)
                {
                    // cout << c << " " << r << " --> " << endl;
                    int got = mini(1, row[r], 0, m - 1, c, c + l - 1);
                    minis.push_back(got);
                }
                multiset<int> ms;
                for (int i = 0; i < mid; i++)
                {
                    ms.insert(minis[i]);
                }
                int mn = *ms.begin();
                for (int i = mid + 1, j = 0; i < n; j++, i++)
                {
                    auto it = ms.find(minis[j]);
                    ms.erase(it);
                    ms.insert(minis[i]);
                    mn = max(mn, *ms.begin());
                }
                if (mn >= mid)
                    g = true;
            }
            if (g)
            {
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return;
    }
};
int main()
{
    return 0;
}