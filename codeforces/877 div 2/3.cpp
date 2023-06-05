#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
bool isp(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}
void solve()
{
    LL a, b;
    cin >> a >> b;
    if (!isp(b))
    {
        int i = 1;
        for (; i <= a * b;)
        {
            for (int j = 0; j < b; i++, j++)
                cout << i << " ";
            cout << endl;
        }
    }
    else
    {
        int arr[a][b];
        int c = 1;
        for (int i = 0; i < a; i++)
        {
            for (int j = 0; j < b; j++)
            {
                arr[i][j] = c++;
            }
        }
        for (int i = 0; i < a; i += 2)
        {
            for (int j = 0; j < b; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
        for (int i = 1; i < a; i += 2)
        {
            for (int j = 0; j < b; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
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
        cout << endl;
    }
    return 0;
}
/*
5 11
67 6
45 4
23 2
1 0
34 3
12 1

56 6
*/
/*

1024

*/