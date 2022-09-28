#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string s;
        cin >> s;
        if (n <= 2)
        {
            cout << s << endl;
        }
        else
        {
            vector<char> v;
            for (auto &val : s)
            {
                v.push_back(val);
            }
            sort(v.begin(), v.end());
            for (auto &val : v)
            {
                cout << val;
            }
            cout << endl;
        }
    }
    return 0;
}