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
    LL s1 = v[0] + v[1], s2 = v[n - 1];
    int i = 2, j = n - 2;
    while (true)
    {
        if (s1 < s2)
        {
            return true;
        }
        if (!(i < j))
            break;
        s1 += v[i++], s2 += v[j--];
    }
    return false;
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
        if (solve())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}