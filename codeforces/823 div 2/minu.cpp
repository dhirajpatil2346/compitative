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
        int l = 0, r = n - 1;
        vector<char> inc;
        vector<char> Inc;
        string ans = "";
        while (l <= s.length() - 1)
        {
            int a = l, b = s.length() - 1;
            char minichar = s[l];
            inc.clear();
            for (int i = a; i <= b; i++)
            {
                minichar = min(s[i], minichar);
            }
            int pos;
            for (int i = a; i <= b; i++)
            {
                if (s[i] == minichar)
                {
                    pos = i;
                    break;
                }
            }
            // cout << l << " " << pos << endl;
            if (s[pos] == '9')
            {
                Inc.push_back('9');
            }
            else
            {
                ans += s[pos];
            }
            for (int i = l; i < pos; i++)
            {
                char p = s[i] + 1;
                inc.push_back(min(p, '9'));
                // s += (min(p, '9'));
            }
            sort(inc.begin(), inc.end());
            for (auto val : inc)
            {
                s += val;
            }
            l = pos + 1;
        }
        sort(inc.begin(), inc.end());
        for (auto val : Inc)
        {
            ans += val;
        }
        cout << ans << endl;
    }
    return 0;
}