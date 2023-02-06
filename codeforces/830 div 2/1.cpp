#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int g = 0;
        vector<int> v(n);
        for (auto &val : v)
        {
            cin >> val;
            g = __gcd(g, val);
        }
        int sc = 0;
        int k = n;
        while (g != 1 && k >= 0)
        {
            if (__gcd(g, k) == 1)
            {
                sc = n - k + 1;
                break;
            }
            k--;
        }
        if (sc == 0)
        {
            cout << sc << endl;
        }
        else if (n == 1)
        {
            cout << 1 << endl;
        }
        else
        {
            cout <<min(sc, 3) << endl;
        }
    }
    return 0;
}