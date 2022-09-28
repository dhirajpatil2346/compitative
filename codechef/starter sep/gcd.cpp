#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0 || b == 0)
        return 0;
    else if (a == b)
        return a;
    else if (a > b)
        return gcd(a - b, b);
    else
        return gcd(a, b - a);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        bool onep = false;
        for (auto &val : v)
        {
            cin >> val;
        }
        int g = 0;
        for (int i = 0; i < n; i++)
        {
            // cout << v[i] <<gcd(g,v[i]) <<endl;
            g = __gcd( v[i],g);
            // cout << g << endl;
        }
        int cnt = 0;
        cout << g << endl;
        int init = 0;
        for (auto &val : v)
        {
            init = __gcd(val, init);
            if (init == g)
            {
                // cout << val << " " << init << endl;
                init = 0;
                cnt++;
            }
        }
        if (cnt >= k)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}