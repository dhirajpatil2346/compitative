#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"
void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n & 1)
    {
        cout << -1 << endl;
        return;
    }
    deque<char> d;
    for (auto &val : s)
        d.push_back(val);
    int op = 0;
    int i = 0, extra = 0;
    vector<int> ans;
    int last = n - 1;
    while (!d.empty())
    {
        if (op > 300)
        {
            cout << -1 << endl;
            return;
        }
        if (d.front() != d.back())
        {
            d.pop_back();
            d.pop_front();
            i++;
            last--;
            continue;
        }
        op++;
        if (d.front() == '0')
        {
            // no issue with i
            ans.push_back(last + 1);
            d.push_back('0');
            d.push_back('1');
            last += 2;
        }
        else
        {
            // f = 1 , b = 1
            ans.push_back(i);
            d.push_front('1');
            d.push_front('0');
            last += 2;
        }
    }
    cout << ans.size() << endl;
    for (auto &val : ans)
        cout << val << " ";
    cout << endl;
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
/*
6
001110
011001
*/