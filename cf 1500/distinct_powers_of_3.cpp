#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<LL> v = {1};
    while (true)
    {
        if (v.back() > 3e18)
            break;
        v.push_back(v.back() * 3);
    }
    int t;
    cin >> t;
    while (t--)
    {
        LL n;
        cin >> n;
        LL N = n;
        vector<LL> track;
        LL uti = 0;
        LL ans = v.back();
        for (LL i = v.size() - 1; i >= 0; i--)
        {
            if (n >= v[i])
            {
                uti += v[i];
                track.push_back(i);
                n -= v[i];
            }
            else
            {
                if (uti + v[i] >= N)
                {
                    ans = min(ans, v[i] + uti);
                }
            }
        }
        if (n == 0)
            cout << N << endl;
        else
            cout << ans << endl;
    }
    return 0;
}