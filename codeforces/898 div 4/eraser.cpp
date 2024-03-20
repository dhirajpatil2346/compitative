#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int op = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'W')
            continue;
        op++;
        for (int j = 0; j < k; j++)
        {
            if ((i + j) < n)
                s[i + j] = 'W';
        }
    }
    cout << op << endl;
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