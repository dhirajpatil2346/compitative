#include <bits/stdc++.h>
using namespace std;
using ld = long double;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<ld> pos(n), flux(n);
    for (auto &val : pos)
        cin >> val;
    for (auto &val : flux)
        cin >> val;
    if (n == 1)
    {
        cout << pos.front() << endl;
        return;
    }
    ld leftval = pos[0] - flux[0], leftpt = 0;
    for (int i = 1; i < n; i++)
        if ((pos[i] - flux[i]) < leftval)
            leftpt = i, leftval = pos[i] - flux[i];
    ld rightval = pos.back() + flux.back(), rightpt = n - 1;
    for (int i = n - 2; i >= 0; i--)
        if ((pos[i] + flux[i]) > rightval)
            rightpt = i, rightval = pos[i] + flux[i];
    ld two = 2;
    ld avg = (rightval + leftval) / two;
    // score = avg - (pos - flux)
    // now we have score
    // score  = x0 - pos + flux
    // x0 = score + pos - flux
    ld score = avg - (pos[leftpt] - flux[leftpt]);
    ld x0 = score + pos[leftpt] - flux[leftpt];
    cout << fixed << x0 << endl;
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