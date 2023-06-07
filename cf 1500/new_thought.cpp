#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    int arr[n][m];
    vector<set<int>> v(m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] != 2)
                v[j].insert(i);
        }
    while (k--)
    {
        int r = 0, c;
        cin >> c;
        c--;
        while (true)
        {
            if (c >= m)
            {
                cout << m << " ";
                break;
            }
            if (c < 0)
            {
                cout << 1 << " ";
                break;
            }
            if (r >= n)
            {
                cout << n << " ";
                break;
            }
            auto it = v[c].lower_bound(r);
            if (it == v[c].end())
            {
                cout << c + 1 << endl;
                break;
            }
            else
            {
                r = *it;
                int OR = r, OC = c;
                if (arr[r][c] == 1)
                    c++;
                else if (arr[r][c] == 2)
                    r++;
                else
                    c--;
                arr[OR][OC] = 2;
                v[OC].erase(it);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}