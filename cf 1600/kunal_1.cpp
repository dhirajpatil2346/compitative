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
    int k;
    cin >> k;
    vector<long double> v(n);
    for (auto &val : v)
        cin >> val;
    long double sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += v[i];
    }
    long double csum = sum;
    pair<int, int> ans = {0, k - 1};
    for (int j = 0, i = k; i < n; i++, j++)
    {
        csum -= v[j];
        csum += v[i];
        // cout << i << " " << csum << endl;
        if (csum < sum)
        {
            sum = csum;
            ans = {j + 1, i};
        }
    }
    cout << ans.first << "\n"
         << ans.second << endl;
    return 0;
}