#include <bits/stdc++.h>
using namespace std;
long long retsum(long long n)
{
    // n--;
    return ((n * (n - 1)) / 2);
}
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        map<long long, long long> m;
        for (long long i = 0; i < n; i++)
        {
            long long x;
            cin >> x;
            m[x]++;
        }
        long long sum = 0;
        for (auto &val : m)
        {
            sum += retsum(val.second);
        }
        cout<<sum<<endl;
    }
    return 0;
}