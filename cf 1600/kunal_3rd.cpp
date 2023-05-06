#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<long long> v(n);
    for (auto &val : v)
        cin >> val;
    // sort(v.begin(), v.end());
    ll sum = 0;
    vector<int> freq(n);
    for (int i = 0; i < n; i++)
    {
        ll maxi = 0;
        for (int j = i; j < n; j++)
        {
            freq[j]++;
            maxi = max(maxi, v[j]);
            sum += maxi;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << " " << freq[i] << endl;
    }
    cout << sum << endl;
    return 0;
}
/*
3 * 2
2 * 1
4 * 4
1 * 1
6 * 6
5 * 1
*/