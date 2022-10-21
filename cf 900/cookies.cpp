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
    vector<int> v(n);
    for (auto &val : v)
    {
        cin >> val;
    }
    int sum = accumulate(v.begin(), v.end(), 0);
    int ans = 0;
    for (auto &val : v)
    {
        if ((sum - val) % 2)
        {
        }
        else
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}