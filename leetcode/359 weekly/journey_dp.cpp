#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    // 0 means correct
    // 1 means incorrect
    int n;
    cin >> n;
    string s;
    cin >> s;
    set<pair<int, int>> correct, incorrect;
    for (int i = 1; i <= n; i++)
    {
        if (s[i - 1] == 'L')
        {
            correct.insert({i, i - 1});
            incorrect.insert({i - 1, i});
        }
        else
        {
            correct.insert({i - 1, i});
            incorrect.insert({i, i - 1});
        }
    }
    vector<vector<int>> left(n + 1, vector<int>(2, 0)), right(n + 1, vector<int>(2, 0));
    for (int i = 1; i <= n; i++)
    {
        // fill correct by checking last correct and check if correct way is there
        if (correct.find({i, i - 1}) != correct.end())
            left[i][0] = 1 + left[i - 1][1];

        // fill incorrect by checking last incorrect and check if incorrect way is there
        if (incorrect.find({i, i - 1}) != incorrect.end())
            left[i][1] = 1 + left[i - 1][0];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        // fill correct by checking last correct and check if correct way is there
        if (correct.find({i, i + 1}) != correct.end())
            right[i][0] = 1 + right[i + 1][1];

        // fill incorrect by checking last incorrect and check if incorrect way is there
        if (incorrect.find({i, i + 1}) != incorrect.end())
            right[i][1] = 1 + right[i + 1][0];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++)
        cout << 1 + left[i][0] + right[i][0] << " ";
    cout << endl;
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