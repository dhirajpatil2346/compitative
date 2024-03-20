#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

pair<int, int> f(string &s)
{
    int n = s.length();
    vector<pair<int, int>> vp(n, {0, 0});
    stack<char> st;
    for (auto &val : s)
    {
        if (val == ' ')
            continue;
        if (st.empty() || (val == 'U' && st.top() != 'D') ||
            (val == 'D' && st.top() != 'U') ||
            (val == 'L' && st.top() != 'R') ||
            (val == 'R' && st.top() != 'L'))
            st.push(val);
        else
            st.pop();
    }
    if (st.empty())
        return {1e9, 1e9};
    int x = 0, y = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == 'U')
            y++;
        if (s[i] == 'D')
            y--;
        if (s[i] == 'L')
            x--;
        if (s[i] == 'R')
            x++;
        vp[i].first = x, vp[i].second = y;
    }
    for (int I = 1; I < n; I++)
    {
        auto p = vp[I];
        auto val = p;
        int X = val.first, Y = val.second;
        int x1 = 0, y1 = 0;
        x = 0, y = 0;
        // cout << X << " " << Y << "  -- >  " << endl;
        for (int i = 1; i < n; i++)
        {
            x = x1, y = y1;
            if (s[i] == 'U')
                y++;
            if (s[i] == 'D')
                y--;
            if (s[i] == 'L')
                x--;
            if (s[i] == 'R')
                x++;
            // cout << "x is : " << x << " y is : " << y << endl;
            if (X == x && Y == y)
            {
                x = x1, y = y1;
            }
            else
            {
                x1 = x, y1 = y;
                // X = x1, Y = y1;
            }
            // cout << "x is : " << x << " y is : " << y << endl;
            // cout << X << " " << Y << endl;
        }
        // cout << I << " " << X << " " << Y << endl;
        if (x == 0 && y == 0)
            return val;
    }
    return {0, 0};
}

void solve()
{
    string s;
    cin >> s;
    string h = " ";
    h += s;
    s = h;
    pair<int, int> p = f(s);
    cout << p.first << " " << p.second << endl;
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
