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
    int mini = *min_element(v.begin(), v.end());
    bool fault = false;
    for (int i = 0; i < n - 2; i++)
    {
        if ((v[i] == mini) && (v[i + 1] == mini) && (v[i + 2] == mini))
            fault = true;
    }
    set<int> index;
    for (int i = 0; i < n; i++)
        if (v[i] == mini)
            index.insert(i);
    for (int i = 2; i < n; i++)
        if (index.find(i) == index.end())
        {
            LL total = v[i] / 3ll;
            v[i - 1] += total;
            v[i - 2] += 2ll * total;
            v[i] -= 3ll * total;
        }
    LL maxi = 0;
    for (auto &val : index)
        maxi = max(maxi, v[val]);
    if (fault)
        maxi = mini;
    cout << maxi << endl;
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