#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    if (n % 2 == 0)
    {
        for (int i = 1; i <= n / 2; i++)
        {
            cout << i + (n + 1) / 2 << " " << i << " ";
        }
        cout << endl;
    }
    else
    {
        for (int i = 1; i <= n / 2; i++)
        {
            cout << i << " " << i + (n + 2) / 2 << " ";
        }
        cout << (n + 1)/2 << endl;
    }
    return 0;
}