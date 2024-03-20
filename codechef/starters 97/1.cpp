#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    string s;
    cin >> n >> s;
    vector<int> scol;
    for (int i = 0; i < n; i++)
        if (s[i] == ':')
        {
            scol.push_back(i);
        }
    int a = 0;
    if (scol.size() <= 1)
    {
        cout << a << endl;
        return;
    }
    for (int i = 0; i < scol.size() - 1; i++)
    {
        int c = 0;
        int ele = scol[i] + 1 - scol[i + 1] - 1 + 1;
        if (ele == 0)
            continue;
        for (int j = scol[i] + 1; j < scol[i + 1]; j++)
        {
            if (s[j] == ')')
                c++;
            else
            {
                c = 0;
                break;
            }
        }
        if (c > 0)
            a++;
    }
    cout << a << endl;
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