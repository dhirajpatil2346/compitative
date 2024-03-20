#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        vector<long long> even, odd;
        for (int i = 0; i < s.length(); i++)
        {
            int dig = s[i] - '0';
            long long x = dig;
            if (x == 0)
                continue;
            if (dig % 2 == 0)
            {
                even.push_back(x);
            }
            else
                odd.push_back(x);
        }
        if (even.size() == 0 && odd.size() == 0)
        {
            cout << 0 << " ";
        }
        else if (even.size() == 0)
        {
            long long ans = -1;
            for (auto &val : odd)
                ans *= val;
            if (ans < 0)
            {
                ans = 0;
            }
            cout << ans << " ";
        }
        else if (odd.size() == 0)
        {
            long long ans = -1;
            for (auto &val : even)
                ans *= val;
            if (ans < 0)
            {
                ans = 0;
            }
            cout << ans << " ";
        }
        else
        {
            long long o = 1, e = 1;
            for (auto &val : even)
                e *= val;
            for (auto &val : odd)
                o *= val;
            long long ans = e - o;
            if (ans < 0)
                ans = 0;
            cout << ans << " ";
        }
    }
    return 0;
}