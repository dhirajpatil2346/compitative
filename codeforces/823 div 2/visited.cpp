#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.length();
        vector<bool> vis(s.length());
        vector<char> v;
        for (auto &val : s)
        {
            v.push_back(val);
        }
        sort(v.begin(), v.end());
        int i = 0, j = 0; // i for string and j for vector
        while (i < n && j < n)
        {
            if (s[i] == v[j])
            {
                vis[i] = true;
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        string ans = "";
        vector<char> inc;
        for (int i = 0; i < n; i++)
        {
            if (vis[i])
            {
                ans += s[i];
                continue;
            }
            char z = s[i] + 1;
            inc.push_back(min(z, '9'));
        }
        sort(inc.begin(), inc.end());
        for (auto &val : inc)
        {
            ans += val;
        }
        cout << ans << endl;
    }
    return 0;
}