#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

bool solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (auto &val : v)
        for (auto &valu : val)
            cin >> valu;

    for (int bit = 0; bit <= 20; bit++)
    {
        if ((1 << bit) >= 1024)
            break;
        vector<int> compulsory_one, compulsory_zero, options;
        for (int i = 0; i < n; i++)
        {
            bool bit_is_there = false, bit_not_there = false;
            for (int j = 0; j < m; j++)
            {
                // cout << ((1 << bit) & v[i][j]) << endl;
                if (((1 << bit) & v[i][j]) > 0)
                    bit_is_there = true;
                else
                    bit_not_there = true;
            }
            // cout << bit_is_there << " " << bit_not_there << endl;
            if (bit_is_there && bit_not_there)
                options.push_back(i);
            else if (bit_is_there)
                compulsory_one.push_back(i);
            else
                compulsory_zero.push_back(i);
        }
        // cout << bit << " " << (compulsory_one.size()) << " " << (compulsory_zero.size()) << " " << (options.size()) << endl;
        if ((compulsory_one.size() % 2) || options.size())
        {
            cout << "TAK" << endl;
            if (compulsory_one.size() % 2)
            {
                // take all compulsory ones
                vector<int> ans(n);
                for (auto &val : compulsory_one)
                    ans[val] = 1;
                // take zeros from compulsory zeros
                for (auto &val : compulsory_zero)
                    ans[val] = 1;
                // take zeros from options
                for (auto &val : options)
                {
                    for (int k = 0; k < m; k++)
                    {
                        if ((v[val][k]) & (1 << bit))
                            continue;
                        ans[val] = k + 1;
                        break;
                    }
                }
                for (auto &val : ans)
                    cout << val << " ";
                cout << endl;
            }
            else
            {
                vector<int> ans(n);
                // take all compulsory ones
                for (auto &val : compulsory_one)
                    ans[val] = 1;
                // take zeros from compulsory zeros
                for (auto &val : compulsory_zero)
                    ans[val] = 1;
                // take single one and other zeros from options
                int lucky_row = options[0];
                for (int k = 0; k < m; k++)
                {
                    if ((v[lucky_row][k]) & (1 << bit))
                    {
                        ans[lucky_row] = k + 1;
                        break;
                    }
                }
                for (int p = 1; p < options.size(); p++)
                {
                    int val = options[p];
                    for (int k = 0; k < m; k++)
                    {
                        if ((v[val][k]) & (1 << bit))
                            continue;
                        ans[val] = k + 1;
                        break;
                    }
                }
                for (auto &val : ans)
                    cout << val << " ";
                cout << endl;
            }
            return true;
        }
    }
    return false;
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
        if (!solve())
            cout << "NIE" << endl;
    }
    return 0;
}