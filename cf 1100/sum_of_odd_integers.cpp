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
        if ((n % 2) && (!(k % 2)))
        {
            cout << "NO" << endl;
        }
        else if ((!(n % 2)) && (k % 2))
        {
            cout << "NO" << endl;
        }
        else
        {
            int sum = 0;
            int j = 1;
            bool got = false;
            for (int i = 0; i < k; i++)
            {

                sum += j;
                j += 2;
                if (sum > n)
                {
                    got = true;
                    break;
                }
            }
            if (got)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
        }
    }
    return 0;
}