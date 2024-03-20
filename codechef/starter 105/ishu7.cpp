#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (auto &val : v)
        cin >> val;
    map<long long, long long> m1;
    for (int i = 0; i < n; i++)
        m1[v[i]] = i;
    sort(v.begin(), v.end());
    long long ans = 0;
    for (long long i = 0; i < n; i++)
    {
        ans += (v[i] * (abs(m1[v[i]] - i)));
    }
    cout << ans << endl;
    return 0;
}