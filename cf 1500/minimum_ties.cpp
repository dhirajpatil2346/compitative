#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    int match = n - 1, tie = 0;
    int win = match / 2, loss = match / 2;
    if (match & 1)
        tie = 1;
    vector<int> w(n, win), l(n, loss), ties(n, tie);
    for (int i = 0; i < n; i++)
    {
        int j = i + 1;
        while (w[i])
        {
            cout << 1 << " ";
            l[j]--, w[i]--;
            j++;
        }
        while (ties[i])
        {
            cout << 0 << " ";
            ties[i]--, ties[j]--;
            j++;
        }
        while (l[i])
        {
            cout << -1 << " ";
            l[i]--, w[j]--;
            j++;
        }
    }
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