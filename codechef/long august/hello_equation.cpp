#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        bool got = false;
        for (int a = 1; a <= x/2; a++)
        {
            int num = x - 2 * a;
            int den = 2 + a;
            cout<<a<<"  "<<num/den<<endl;
            
            if (num % den == 0 && (num / den) > 0)
            {
                // cout<<a<<"  "<<num/den<<endl;
                got = true;
                break;
            }
        }
        if (got)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}