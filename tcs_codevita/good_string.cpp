#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a, b;
    cin >> a >> b;
    set<LL> s;
    for (auto &val : a)
        s.insert(int(val));
    LL pre = a[0];
    LL ans = 0;
    for (int i = 0; i < (int)b.length(); i++)
    {
        LL val = b[i];
        LL curr = val;
        // cout << char(pre) << " ";
        auto it = s.lower_bound(val);
        if (it == s.end())
        {
            // cout << "if " << i << endl;
            ans += abs(curr - (*(prev(s.end()))));
            // cout << char(*prev(s.end())) << endl;
            pre = *prev(s.end());
        }
        else if (*it == curr)
        {
            // cout << endl;
            continue;
        }
        else if (it == s.begin())
        {
            // cout << "elif " << i << endl;
            ans += abs(*it - curr);
            // cout << " " << char(curr) << endl;
            pre = *it;
        }
        else
        {
            // cout << "else " << i << endl;
            LL val1 = *it;
            LL val2 = *(prev(it));
            // if (i == 0)
            // {
            //     if (abs(curr - val1) <= abs(curr - val2))
            //     {
            //         ans += abs(curr - val1);
            //         pre = val1;
            //     }
            //     else
            //     {
            //         ans += abs(curr - val2);
            //         pre = val2;
            //     }
            //     continue;
            // }
            // cout << char(val1) << " " << char(val2) << endl;
            if (abs(curr - val1) != abs(curr - val2))
                if (abs(curr - val1) <= abs(curr - val2))
                {
                    ans += abs(curr - val1);
                    //  cout << char(pre) << " " << char(val1) << endl;
                    // cout << abs(curr - val1) << endl;
                    // cout << char(val1) << endl;
                    pre = val1;
                }
                else
                {
                    // cout << char(val2) << endl;
                    ans += abs(curr - val2);
                    //  cout << char(curr) << " " << char(val2) << endl;
                    // cout << abs(curr - val2) << endl;

                    pre = val2;
                }
            else
            {
                if (abs(pre - val1) <= abs(pre - val2))
                {
                    // cout << abs(curr - val1) << endl;

                    // cout << char(val1) << endl;
                    //  cout << char(pre) << " " << char(val1) << endl;
                    ans += abs(pre - val1);
                    pre = val1;

                }
                else
                {
                    // cout << abs(curr - val2) << endl;
                    // cout << char(pre) << " " << char(val2) << endl;
                    ans += abs(pre - val2);
                    pre = val2;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}