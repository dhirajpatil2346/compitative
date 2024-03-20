#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n, k, x;
    cin >> n >> k >> x;
    vector<int> v;
    for (int i = 0; i < k; i++)
        v.push_back(i);
    // now min ex is k
    // now take x as next
    if (x == k)
        x--;
    while (v.size() < n)
        v.push_back(x);
    if (v.size() > n)
    {
        cout << -1 << endl;
        return;
    }
    if (*max_element(v.begin(), v.end()) > x)
    {
        cout << -1 << endl;
        return;
    }
    cout << accumulate(v.begin(), v.end(), 0) << endl;
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