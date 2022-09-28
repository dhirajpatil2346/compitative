#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s = to_string(n);
        int len = s.length();
        bool got = true;
        if (n % 2 == 0)
        {
            cout << 0 << endl;
            got = false;
        }
        else
        {
            int j = 1;
            while (--len)
            {
                int k = pow(10,len);
                // cout<<k<<"   "<<n / k<<endl;
                if ((n / k) % 2 == 0)
                {
                    cout << j << endl;
                    got = false;
                    break;
                }
                else
                {
                    j++;
                }
            }
        }
        if (got)
        {
            cout << -1 << endl;
        }
    }
    return 0;
}