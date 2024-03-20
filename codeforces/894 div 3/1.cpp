#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
bool solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (auto &val : v)
        cin >> val;
    int col = 0;
    bool V = false, I = false, K = false, A = false;
    for (; col < m;)
    {
        if (V)
            break;
        for (int i = 0; i < n; i++)
        {
            if (v[i][col] == 'v')
            {
                V = true;
                col++;
                break;
            }
        }
        if (!V)
            col++;
    }
    // cout << col << endl;
    for (; col < m;)
    {
        if (I)
            break;
        for (int i = 0; i < n; i++)
        {
            if (v[i][col] == 'i')
            {
                I = true;
                col++;
                break;
            }
        }
        if (!I)
            col++;
    }
    for (; col < m;)
    {
        if (K)
            break;
        for (int i = 0; i < n; i++)
        {
            if (v[i][col] == 'k')
            {
                K = true;
                col++;
                break;
            }
        }
        if (!K)
            col++;
    }
    for (; col < m;)
    {
        if (A)
            break;
        for (int i = 0; i < n; i++)
        {
            if (v[i][col] == 'a')
            {
                A = true;
                col++;
                break;
            }
        }
        if (!A)
            col++;
    }
    // cout << V << I << K << A << endl;
    return (V & I & K & A);
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
        if (solve())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}