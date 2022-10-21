#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s1, s2;
        cin >> s1 >> s2;
        map<char, int> m1, m2;
        for (int i = 0; i < n; i++)
        {
            m1[s1[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            m2[s2[i]]++;
        }
        int ans = 0;
        for (auto &val : m1)
        {
            ans = max(ans, min(val.second, m2[val.first]));
        }
        cout << ans << endl;
    }
    return 0;
}