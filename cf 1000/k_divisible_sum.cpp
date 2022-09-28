#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        if (k == n)
        {
            cout << 1 << endl;
        }
        else if (n == 1)
        {
            cout << k << endl;
        }
        else if (n < k)
        {
            if (k % n == 0)
            {
                cout << k / n << endl;
            }
            else
            {
                cout << k / n + 1 << endl;
            }
        }
        else if(n>=k)
        {
            if(n%k==0)
            {
                cout<<1<<endl;
            }
            else
            {
                cout<<2<<endl;
            }
        }
        else
        {
            int nk = 0;
            while (nk <= n)
            {
                nk += k;
            }
            if (nk % n == 0)
            {
                cout << nk / n << endl;
            }
            else
            {
                cout << nk / n + 1 << endl;
            }
        }
    }
    return 0;
}