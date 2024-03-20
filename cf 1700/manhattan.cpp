#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    LL ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i == n)
        {
            ans++;
            break;
        }
        pair<int, int> defslope = {0, 0};
        int x1 = v[i], x2 = v[i + 1], y1 = i, y2 = i + 1;
        defslope.first = y2 - y1, defslope.second = x2 - x1;
        int g = __gcd(abs(defslope.first), abs(defslope.second));
        defslope.first /= g, defslope.second /= g;
        if ((defslope.first < 0 && defslope.second < 0) || (defslope.first > 0 && defslope.second < 0))
            defslope.first *= -1, defslope.second *= -1;
        LL ele = 2;
        int j = i + 2;
        cout << defslope.first << " " << defslope.second << endl;
        for (; j <= n;)
        {
            pair<int, int> currslope = {0, 0};
            x1 = v[j], x2 = v[i + 1], y1 = j, y2 = i + 1;
            currslope.first = y2 - y1, currslope.second = x2 - x1;
            g = __gcd(abs(currslope.first), abs(currslope.second));
            currslope.first /= g, currslope.second /= g;
            if ((currslope.first < 0 && currslope.second < 0) || (currslope.first > 0 && currslope.second < 0))
                currslope.first *= -1, currslope.second *= -1;
            cout << j << " " << currslope.first << " " << currslope.second << endl;
            if (currslope.first == defslope.first && currslope.second == defslope.second)
            {
                break;
            }
            else
            {
                ele++;
                j++;
            }
        }
        // cout << i << " " << ele << endl;
        i = j;

        ans += (ele * (ele + 1)) / 2ll;
    }
    cout << ans << endl;
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