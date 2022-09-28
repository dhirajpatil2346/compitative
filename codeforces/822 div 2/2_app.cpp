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
        if (n == 1)
        {
            cout << 1 << endl;
        }
        else if (n == 2)
        {
            cout << 1 << "\n1 1" << endl;
        }
        else
        {
            cout << 1 << "\n1 1" << endl;
            for (int i = 3; i <= n; i++)
            {
                cout << 1 << " ";
                for (int j = 2; j < i; j++)
                {
                    cout << "0 ";
                }

                cout << 1 << endl;
            }
        }
    }
    return 0;
}