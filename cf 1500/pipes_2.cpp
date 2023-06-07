#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> v(2, vector<int>(n));
    for (auto &val : v)
    {
        for (auto &valu : val)
        {
            char ch;
            cin >> ch;
            valu = ch - '0';
            if (valu <= 2)
                valu = 1;
            else
                valu = 3;
        }
    }
    // for (auto &val : v)
    // {
    //     for (auto &valu : val)
    //         cout << valu << " ";
    //     cout << endl;
    // }
    int pd = 0; // 0 means left // 1 up // 2  for down
    int sc = 0, sr = 0;
    while (true)
    {
        // cout << sr << " " << sc << " " << pd << endl;
        if (sc == n)
        {
            if (sr == 1)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
            return;
        }
        if (sr < 0 || sr == 2)
        {
            cout << "NO" << endl;
            return;
        }
        if (pd == 0)
        {
            if (v[sr][sc] == 1)
            {
                pd = 0;
                sc++;
            }
            else
            {
                if (sr == 0)
                {
                    pd = 1;
                    sr++;
                }
                else
                {
                    sr--;
                    pd = 2;
                }
            }
        }
        else if (pd == 1)
        {
            if (v[sr][sc] == 1)
            {
                pd = 1;
                sr++;
            }
            else
            {
                pd = 0;
                sc++;
            }
        }
        else if (pd == 2)
        {
            if (v[sr][sc] == 1)
            {
                pd = 2;
                sr--;
            }
            else
            {
                pd = 0;
                sc++;
            }
        }
    }
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