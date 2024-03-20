#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    LL n, k;
    cin >> n >> k;
    LL par = (n / 2ll) * 3ll;
    par %= 2ll;
    if ((k % 2) != par)
    {
        cout << -1 << endl;
        return;
    }
    LL terms = n / 2;
    vector<LL> v;
    LL fct = k / terms;
    cout << terms << " " << fct << endl;
    if (fct & 1ll)
    {
        while (v.size() < n)
        {
            // make blocks of two
            v.push_back(fct / 2ll);
            v.push_back(v.back() + 1ll);
        }
    }
    else
    {
    }
    bool fault = false;
    if (v.size() != n)
        fault = true;
    for (auto &val : v)
    {
        if (val >= 1 && val <= 1e5)
            continue;
        fault = true;
    }
    if (fault)
        cout << -1 << endl;
    else
    {
        for (auto &val : v)
            cout << val << " ";
        cout << endl;
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