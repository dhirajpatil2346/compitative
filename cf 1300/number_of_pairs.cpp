#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> v(n);
    for (auto &val : v)
    {
        cin >> val;
    }
    sort(v.begin(), v.end());
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int f1 = -1, f2 = -2;
        for (int j = i + 1; j < n; j++)
        {
            if ((v[i] + v[j]) >= l)
            {
                f1 = j;
                break;
            }
        }
        for (int j = n - 1; j >= i + 1; j--)
        {
            if ((v[i] + v[j]) <= r)
            {
                f2 = j;
                break;
            }
        }
        ans += f2 - f1 + 1;
    }
    cout << ans << endl;

    return 0;
}