#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 4)
        {
            cout << "2 4 1 3" << endl;
        }
        else
        {

            if (n % 2 == 0)
            {
                int start = ((n + 1) / 2) + 1;
                int ns = 1;
                int p = start;
                while (start <= n)
                {
                    cout << start++ << " " << ns++ << " ";
                }
                cout << endl;
            }
            else
            {
                int start = 1;
                int ns =1+ (1+n)/2;
                int p = start;
                while (start <= n / 2)
                {
                        cout << start++ << " " << ns++ << " ";

                }
                cout << (n+1)/2 << endl;
            }
        }
    }
    return 0;
}