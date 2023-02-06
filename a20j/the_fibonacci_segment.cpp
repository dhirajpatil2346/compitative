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
    int i = 2;
    int ans = 0;
    while (i < n)
    {
        int a = 0;
        if (v[i] != (v[i - 1] + v[i - 2]))
        {
            i++;
        }
        else
        {
            while (i < n && (v[i] == (v[i - 1] + v[i - 2])))
            {
                // cout << i << endl;
                a++;
                i++;
            }
            ans = max(a, ans);
        }
    }
    cout << ((ans == 0) ? min(2, n) : ans + 2) << endl;
    return 0;
}