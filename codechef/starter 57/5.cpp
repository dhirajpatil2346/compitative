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
        int a, b;
        cin >> a >> b;
        if (a % 2 && b % 2)
        {
            cout << "No" << endl;
        }
        else if (a % 2 == 0 && b % 2 == 0)
        {
            cout << "Yes" << endl;
        }
        else
        {
            int maxi = max(a, b), mini = min(a, b);
            if (mini == 1)
            {
                cout << "No" << endl;
            }
            else
            {
                cout << "Yes" << endl;
            }
        }
    }
    return 0;
}