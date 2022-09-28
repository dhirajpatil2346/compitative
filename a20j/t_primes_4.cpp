#include <bits/stdc++.h>
using namespace std;

int main()
{
    int maxi = 1e7 + 1;
    vector<bool> prime(maxi, true);
    for (long long i = 2; i < maxi; i++)
    {
        if (!prime[i])
        {
            continue;
        }
        for (long long j = 2 * i; j < maxi; j += i)
        {
            prime[j] = false;
        }
    }
    int n;
    cin >> n;
    vector<long long> v(n);
    for (auto &val : v)
    {
        cin >> val;
    }
    for (int i = 0; i < n; i++)
    {
        bool got = false;
        long long sqr = sqrt(v[i]);
        long long z = sqr * sqr;
        if (v[i] == 4)
        {
            cout << "YES" << endl;
        }
        else if (v[i] <= 2)
        {
            cout << "NO" << endl;
        }
        else if (v[i] % 2 == 0)
        {
            cout << "NO" << endl;
        }
        else if (z == v[i])
        {
            if (prime[sqr])
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}