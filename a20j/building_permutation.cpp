#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    long long ans = 0;
    for (long long i = 0; i < n; i++)
    {

        // cout<<i<<"  "<<v[i]<<"    "<<abs(i-v[i])<<endl;
        ans += abs(i+1 - v[i]);
    }
    cout << ans << endl;
    return 0;
}