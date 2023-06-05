#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int one = 0, np = 0, two = 0;
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (v[i] == 1)
            one = i;
        if (v[i] == n)
            np = i;
        if (v[i] == 2)
            two = i;
    }
    // 1 2 n --> replace 2 and n
    // 1 n 2 --> no  need
    // 2 1 n
    // 2 n 1 --> no  need
    // n 1  2 --> check
    // n 2 1
    if (one <= two && two <= np)
    {
        cout << two + 1 << " " << np + 1 << endl;
    }
    else if ((one <= np && np <= two) || (two <= np && np <= one))
    {
        cout << "1 1" << endl;
    }
    else if (two <= one && one <= np)
    {
        cout << one + 1 << " " << np + 1 << endl;
    }
    else if (np <= one && one <= two)
    {
        // search for 3
        // n 1  2 --> check
        // 1 n 2
        cout << one + 1 << " " << np + 1 << endl;
    }
    else
    {
        // n 2 1
        cout << np + 1 << " " << two + 1 << endl;
    }
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
/*


*/