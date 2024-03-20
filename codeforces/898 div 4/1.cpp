#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    string a;
    cin >> a;
    for (int i = 0; i < 3; i++)
        for (int j = i; j < 3; j++)
        {
            swap(a[i], a[j]);
            if (a == "abc")
            {
                cout << "YES" << endl;
                return;
            }
            swap(a[i], a[j]);
        }
    cout << "NO" << endl;
    return;
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