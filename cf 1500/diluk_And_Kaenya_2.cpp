#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        vector<pair<int, int>> vp(n, {0, 0});
        map<char, int> m;
        m['D'] = 0, m['K'] = 0;
        for (int i = 0; i < n; i++)
        {
            m[s[i]]++;
            if (m['D'] == 0 || m['K'] == 0)
            {
                vp[i] = {m['D'], m['K']};
            }
            else
            {
                int g = __gcd(m['D'], m['K']);
                vp[i] = {m['D'] / g, m['K'] / g};
            }
        }
        int p = -1;
        for (int i = 0; i < n; i++)
        {
            if (vp[i].first == 0 || vp[i].second == 0)
            {
                cout << i + 1 << " ";
                p = i;
            }
            else
            {
                break;
            }
        }
        map<pair<int, int>, vector<int>> mp;
        for (int i = p + 1; i < n; i++)
        {
            mp[vp[i]].push_back(i);
        }
        for (int i = p + 1; i < n; i++)
        {
            int pos = lower_bound(mp[vp[i]].begin(), mp[vp[i]].end(), i) - mp[vp[i]].begin() + 1;
            cout << pos << " ";
        }
        cout << endl;
    }
    return 0;
}