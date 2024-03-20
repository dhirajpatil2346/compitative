#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n, k;
    cin >> n >> k;
    if (k % 2 == 0)
    {
        // parity can change
        string s;
        cin >> s;
        vector<char> v;
        for (auto &val : s)
            v.push_back(val);
        sort(v.begin(), v.end());
        for (auto &val : v)
            cout << val;
        cout << endl;
    }
    else
    {
        string s;
        cin >> s;
        vector<char> even, odd;
        for (int i = 0; i < n; i++)
            if (i & 1)
                odd.push_back(s[i]);
            else
                even.push_back(s[i]);
        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end());
        int c = 0;
        int i = 0, j = 0;
        for (int p = 0; p < n; p++)
        {
            if (p & 1)
                cout << odd[j++];
            else
                cout << even[i++];
        }
        cout << endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}