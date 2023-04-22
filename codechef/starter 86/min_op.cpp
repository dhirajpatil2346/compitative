#include <bits/stdc++.h>
using namespace std;
#define LL long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, M;
        cin >> n >> M;
        vector<LL> v(n);
        for (auto &val : v)
            cin >> val;
        LL g = v[0];
        for (auto &val : v)
            g = __gcd(g, val);
        int cnt = 0;
        for (auto &val : v)
            if (val == g)
                cnt++;
        int f = n - cnt;
        if (f == 0)
            cout << 0 << endl;
        else
        {
            cout << 1 << endl
                 << g << endl;
        }
    }
    return 0;
}