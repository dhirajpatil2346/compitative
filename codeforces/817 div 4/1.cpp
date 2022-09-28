#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<char> a = {'T', 'i', 'm', 'u', 'r'};
    sort(a.begin(), a.end());
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<char> v(n);
        int i = 0;
        for (auto &val : s)
        {
            v[i] = val;
            i++;
        }
        sort(v.begin(), v.end());
        if (v == a)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}