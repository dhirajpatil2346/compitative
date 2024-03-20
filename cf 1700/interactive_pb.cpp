#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 1; i <= n; i++)
    {
        cin>>v[i-1];
        cout << "? " << i << endl;
        fflush(stdout);
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (v[i] < (min(v[i - 1], v[i + 1])))
        {
            cout << "! " << i + 1 << endl;
            fflush(stdout);
        }
    }
}
int main()
{
    solve();
    return 0;
}