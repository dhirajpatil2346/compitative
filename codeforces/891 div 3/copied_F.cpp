#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    map<LL, LL> m;
    for (int i = 0; i < n; i++)
    {
        LL x;
        cin >> x;
        m[x]++;
    }
    int q;
    cin >> q;
    while (q--)
    {
        LL b, c;
        cin >> b >> c;
        // x^2 - bx + c = 0
        // D =( -b +- (b^2 - 4ac) ) / 2a
        if ((b * b - 4ll * c) < 0)
        {
            cout << 0 << endl;
            continue;
        }
        LL D = b * b - 4 * c;
        if (D < 0)
        {
            cout << 0 << " ";
        }
        else
        {
            LL d1 = (b - sqrt(D)) / 2ll;
            LL d2 = (b + sqrt(D)) / 2ll;
            if ((d1 + d2) != b || d1 * d2 != c)
            {
                cout << 0 << " ";
            }
            else if (d1 == d2)
            {
                cout << (m[d1] * (m[d1] - 1ll)) / 2ll << " ";
            }
            else
                cout << m[d1] * m[d2] << " ";
        }
    }
    cout << endl;
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