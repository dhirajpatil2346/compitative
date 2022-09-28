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
        for (auto &val : v)
        {
            cin >> val;
        }
        long long c = 0;
        vector<bool> made(n + 1);
        for (long long i = 0; i < n;)
        {
            bool got = false;
            long long x = v[i];
            for (long long j = i + 1; j < n; j++)
            {
                x ^= v[j];
                if (x == 0)
                {
                    if (v[i] == v[j] && made[i] == false)
                    {
                        cout << i << j << endl;
                        made[i] = true;
                        made[j] = true;
                        got = true;
                        c += 2;
                        i = j + 1;
                    }
                    else
                    {
                        got = true;
                        // cout << i << " " << j << endl;
                        c++;
                        made[j] = true;
                        i = j + 1;
                        // cout << i << endl;
                    }
                }
            }
            if (!got)
            {
                i++;
            }
        }
        // bool allzero = true;
        // for (long long i = 0; i < n; i++)
        // {
        //     if (v[i])
        //     {
        //         allzero = false;
        //     }
        // }
        // if (allzero)
        // {
        //     for (long long i = 0; i < n; i++)
        //     {
        //         if (!made[i] && v[i] == 0)
        //         {
        //             c++;
        //         }
        //     }
        // }
        cout << c << endl;
    }
    return 0;
}