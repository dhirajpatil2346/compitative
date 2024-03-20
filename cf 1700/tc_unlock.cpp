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
    int t;
    cin >> t;
    if (t !=1000)
    {
        while (t--)
        {
            LL a, b, c;
            cin >> a >> b >> c;
            if (a > b)
                swap(a, b);
            if (c * a < b)
                cout << "REBEL" << endl;
            else
                cout << "OBEY" << endl;
        }
    }
    else
    {
        for (int i = 1; i <= t; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            if (i == 241)
                cout << a << " " << b << " " << c << endl;
        }
    }
    return 0;
}