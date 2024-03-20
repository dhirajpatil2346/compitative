#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<LL> v(2);
    v[0] = 2, v[1] = 3;
    LL c = 4;
    LL t = 3;
    while (v.size() < n)
    {
        LL z = v.size();
        while (((t * c) % (v[z - 1] + v[z - 2])) == 0)
            c++;
        v.push_back(c);
        c++;
    }
    for (auto &val : v)
        cout << val << " ";
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