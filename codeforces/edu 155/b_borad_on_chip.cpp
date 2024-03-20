/*
60000
05000
00000
00000
00000
*/
#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n;
    cin >> n;
    vector<LL> a(n), b(n);
    for (auto &val : a)
        cin >> val;
    for (auto &val : b)
        cin >> val;
    cout<<min(accumulate(a.begin(), a.end(), 0ll) + n * (*min_element(b.begin(), b.end())), accumulate(b.begin(), b.end(), 0ll) + n * (*min_element(a.begin(), a.end())))<<endl;
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