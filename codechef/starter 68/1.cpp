#include <bits/stdc++.h>
using namespace std;
#define ll long long

long long res(long long n)
{
    if (n == 0)
    {
        return 1;
    }
    long long k = res(n / 2);
    if (n % 2)
    {
        return k * k * 2;
    }
    return k * k;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        long long total = res(k);
        for (int i = 0; i < n; i++)
        {
            total /= 2;
        }
        cout << total << endl;
    }
    return 0;
}