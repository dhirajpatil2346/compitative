#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
bool solve()
{
    int n;
    cin >> n;
    vector<LL> v(n);
    for (auto &val : v)
        cin >> val;
    sort(v.begin(), v.end());
    for (int i = 2; i < n; i++)
        if (v[i] < (v[i - 1] + v[i - 2]))
            return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if (solve())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}