#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int neg = 0;
        bool ngot = true;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x == 0)
            {
                ngot = false;
            }
            if (x < 0)
            {
                neg++;
            }
        }
        if (ngot)
        {
            cout << neg % 2 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    return 0;
}