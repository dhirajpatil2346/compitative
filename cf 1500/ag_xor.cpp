#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    vector<LL> track;
    LL a = 0;
    for (auto &val : v)
    {
        a ^= val;
        track.push_back(a);
    }
    bool sat = false;
    LL tresh = track.back();
    a = 0;
    LL c = 0;
    for (auto &val : v)
    {
        a ^= val;
        if (a == tresh)
        {
            c++;
            a = 0;
        }
    }
    if (track.back() == 0 || c > 1)
    {
        sat = true;
    }

    track.clear();
    if (sat)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}