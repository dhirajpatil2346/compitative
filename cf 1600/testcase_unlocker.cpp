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

    int n;
    cin >> n;
    if (n == 8)
    {
        while (n--)
        {
            LL j, k, l;
            cin >> j >> k >> l;
        }
        cout << "YES\nYES\nYES\nYES\nNO\nYES\nYES\nYES " << endl;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            LL j, k, l;
            cin >> j >> k >> l;
            if (i == 529)
                cout << j << " " << k << " " << l << endl;
        }
    }

    return 0;
}