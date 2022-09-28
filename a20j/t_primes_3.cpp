#include <bits/stdc++.h>
using namespace std;

bool isPrime(long long n)
{
    if (n == 2)
    {
        return true;
    }
    if (n == 1)
    {
        return false;
    }
    bool got = true;
    long long sqr = sqrt(n);
    for (int i = 2; i <= sqr; i++)
    {
        if (n % i == 0)
        {
            got = false;
            break;
        }
    }

    return got;
}

int main()
{
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
        // cout << sqr * sqr << "  " << v[i] << endl;
        long long z = sqr * sqr;
        // cout<<sqr<<endl;
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
            // cout<<sqr<<endl;
            if (isPrime(sqr))
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