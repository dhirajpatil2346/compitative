#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll lcm(ll a, ll b)
{
    return (a * b) / __gcd(a, b);
}
bool isPrime(int n)
{
    bool got = false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            got = true;
            break;
        }
    }

    return got;
}

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
        vector<int> v = {1};
        if (n % 2)
        {
            cout<<sqrt(n)<<endl;
            for (int i = 2; i <= sqrt(n); i++)
            {
                if (n % i == 0)
                {
                    for (int j = i; j <= n; j += i)
                    {
                        v.push_back(j);
                    }
                }
            }
            int l = 1, r = n - 1;
            int minLcm = lcm(1, n - 1);
            for (auto &val : v)
            {
                cout << val << " ";
            }
            cout << endl;
            for (int i = 0; i < v.size(); i++)
            {
                int x = v[i], y = n - x;
                int h = lcm(x, y);
                if (min(x, y) == 0)
                {
                    continue;
                }

                if (h < minLcm)
                {
                    minLcm = h;
                    l = x, r = y;
                }
            }
            cout << l << " " << r << endl;
        }
        else
        {
            cout << n / 2 << " " << n / 2 << endl;
        }
    }
    return 0;
}