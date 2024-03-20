#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
class Solution
{
public:
    long long minimumSteps(string s)
    {
        int n = s.length();
        set<LL> zero, one;
        LL ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
                zero.insert(i);
            else
                one.insert(i);
        }
        while (one.size() && zero.size())
        {
            // i can swap only for one < zero
            // cout << one.size() << " " << zero.size() << endl;
            while (one.size() && zero.size())
            {
                // cout << "-> " << *prev(one.end()) << " " << *prev(zero.end()) << endl;
                if (*prev(one.end()) > *prev(zero.end()))
                    one.erase(prev(one.end()));
                else
                    break;
            }
            if (one.size() && zero.size())
            {
                ans += (*prev(zero.end()) - *prev(one.end()));
                int o = *prev(one.end()), z = *prev(zero.end());
                // cout << o << " " << z << endl;
                one.erase(prev(one.end())), zero.erase(prev(zero.end()));
                one.insert(z), zero.insert(o);
            }
        }
        return ans;
    }
};
// 1100 // 0101
// 0010
// 1110 // 0111

int main()
{
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution sc;
        cout << sc.minimumSteps(s) << endl;
    }
    return 0;
}