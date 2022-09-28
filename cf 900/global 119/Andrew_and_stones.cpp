#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> v(n);
        for (long long i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        bool got = true;
        long long cnt = 0;
        if (n == 3 && v[1] % 2 != 0)
        {
            cout << -1 << endl;
            got = false;
        }
        else
        {
            for (long long i = 1; i < n - 1; i++)
            {
                if (v[i] > 1)
                {
                    // cout<<n<<endl;
                    got = false;
                }
            }
            if (got)
            {
                cout << -1 << endl;
            }
            else
            {
                for (long long i = 1; i < n - 1; i++)
                {
                    if (v[i] % 2 == 0)
                    {
                        cnt += v[i] / 2;
                    }
                    else
                    {
                        cnt += v[i] / 2 + 1;
                    }
                }
                cout << cnt << endl;
            }
        }
    }
    return 0;
}