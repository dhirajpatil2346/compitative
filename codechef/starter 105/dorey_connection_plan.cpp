#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
bool solve()
{
    LL n, c;
    cin >> n >> c;
    vector<LL> v(n + 1), p(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        p[i] = v[i] + p[i - 1];
    }
    vector<LL> z(n + 2);
    for (LL i = 1; i <= n; i++)
    {
        if (p[i] >= (i * c))
        {

            z[1]++;
            z[i + 1]--;
        }
        
    }
    for (int i = 1; i <= n; i++)
        z[i] += z[i - 1];
    bool fault = false;
    for (int i = 1; i <= n; i++)
    {
        if (z[i] == 0)
            fault = true;
    }
    return !fault;
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