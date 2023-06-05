#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

void nxt(string s)
{
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int pos = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            pos = i;
            break;
        }
    }
    if (pos == -1)
    {
        n /= 2;
        cout << 1 << " " << 2 * n << " " << 1 << " " << n << endl;
        return;
    }
    pair<int, int> p1 = {pos + 2, n}, p2 = {pos + 1, n};
    // cout << pos << endl;
    // cout << n - (pos + 2) - 1 << endl;
    if ((n - (pos + 2) + 1) >= (n / 2))
    {
        cout << pos + 1 << " " << n << " " << pos + 2 << " " << n << endl;
    }
    else
    {
        pos = -1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] == '0')
            {
                pos = i;
                break;
            }
        }
        cout << 1 << " " << pos + 1 << " " << 1 << " " << pos << endl;
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