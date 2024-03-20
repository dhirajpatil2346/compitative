#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

vector<vector<int>> v(10, vector<int>(10));
void solve()
{
    vector<string> s(10);
    for (auto &val : s)
        cin >> val;
    int sum = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            if (s[i][j] == 'X')
                sum += v[i][j];
    cout << sum << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    v = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
        {1, 2, 3, 3, 3, 3, 3, 3, 2, 1},
        {1, 2, 3, 4, 4, 4, 4, 3, 2, 1},
        {1, 2, 3, 4, 5, 5, 4, 3, 2, 1},
        {1, 2, 3, 4, 5, 5, 4, 3, 2, 1},
        {1, 2, 3, 4, 4, 4, 4, 3, 2, 1},
        {1, 2, 3, 3, 3, 3, 3, 3, 2, 1},
        {1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}