#include <bits/stdc++.h>
using namespace std;
#define LL long long
using ld = long double;
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<ld> pos(n), dress(n);
    for (auto &val : pos)
        cin >> val;
    for (auto &val : dress)
        cin >> val;
    ld l = 0, r = *max_element(pos.begin(), pos.end());
    ld cost = 0;
    ld two = 2;
    for (auto &val : pos)
        cost += abs(val - ((l + r) / 2));
    
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
/*

7 + 2 + 3 + 14
2 6 3
3 6 5

9 3
6 5

14 
6

*/