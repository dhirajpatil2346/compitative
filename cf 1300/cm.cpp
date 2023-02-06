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
        ll n;
        cin >> n;
        vector<ll> factors;
        for (ll i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                factors.push_back(i);
            }
        }
        if (factors.size() == 1)
        {
            cout << 1 << " " << n - 1 << endl;
        }
        else
        {
            cout << n / factors[1] << " " << n - (n / factors[1]) << endl;
        }
    }
    return 0;
}