#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<long long> v(n), v1(n);
    for (long long i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        v[i] = x;
        v1[i] = x;
    }
    sort(v1.begin(), v1.end());
    vector<long long> prefix(n), prefix1(n);
    for (long long i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + v[i - 1];
        prefix1[i] = prefix1[i - 1] + v1[i - 1];
    }
    long long t;
    cin >> t;
    while (t--)
    {
        long long type, l, r;
        cin >> type >> l >> r;
        if (type == 1)
        {
            cout << v[r - 1] + prefix[r - 1] - prefix[l - 1] << endl;
        }
        else
        {
            cout << v1[r - 1] + prefix1[r - 1] - prefix1[l - 1] << endl;
        }
    }
    return 0;
}