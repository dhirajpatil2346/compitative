#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LL long long
#define endl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        LL n;
        cin >> n;
        LL sum = 1;
        for (LL i = 2; i * i <= n; i++)
        {
            ll k = i;
            while (n % i == 0)
            {
                if ((n / i) == i)
                {
                    sum += i;
                }
                else
                {
                    sum += i;
                    sum += (n / i);
                }
                n /= i;
            }
        }
        cout << sum << endl;
    }

    return 0;
}