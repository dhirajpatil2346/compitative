#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<vector<char>> v(n, vector<char>(n));
    for (auto &val : v)
        for (auto &valu : val)
            cin >> valu;
    vector<vector<int>> left(n, vector<int>(n, 0));
    vector<vector<int>> right(n, vector<int>(n, 0));
    vector<vector<int>> up(n, vector<int>(n, 0));
    int ans = 0;
    for (int i = 0, j = 0; j < n; j++)
        if (v[i][j] == '1')
        {
            ans++;
            left[i][j] = 1, right[i][j] = 1, up[i][j] = 1;
        }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x = 0;
            int y = 0;
            up[i][j] = up[i - 1][j];
            y += up[i][j];
            if (j > 0)
            {
                left[i][j] = left[i - 1][j - 1];
                y += left[i][j];
            }

            if ((j + 1) < n)
            {
                right[i][j] += right[i - 1][j + 1];
                y += right[i][j];
            }
            if (y & 1)
                if (v[i][j] == '0')
                    v[i][j] = '1';
                else
                    v[i][j] = '0';

            cout << i << " " << j << " " << y << endl;
            if (v[i][j] == '1')
            {
                // cout << y << endl;
                v[i][j] = '0';
                cout << i << " " << j << endl; 
                ans++;
                up[i][j]++;
                left[i][j]++;
                right[i][j]++;
            }
        }
    }
    cout << ans << endl;
}
int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}