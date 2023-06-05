#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define endl "\n"

bool freq(int ind, string s)
{
    // cout << ind << endl;
    int n = s.length();
    string req = "abacaba";
    int p = 0;
    int i = ind, j = 0;
    while (j < req.size())
        s[i++] = req[j++];

    for (i = 0; i < n; i++)
    {
        if (s[i] != '?')
            continue;
        s[i] = 'z';
    }
    for (i = 0; i < s.length(); i++)
    {
        if ((i + 6) >= s.length())
            break;
        bool g = true;
        for (j = 0; j < req.size(); j++)
        {
            if (s[i + j] != req[j])
            {
                g = false;
                break;
            }
        }
        p += g;
    }
    return (p == 1);
}

bool can(int ind, string &s)
{
    string req = "abacaba";
    int i = ind, j = 0;
    if ((ind + 6) >= s.length())
        return false;
    while (i < s.length() && j < req.length())
    {
        if (s[i] == '?' || (s[i] == req[j]))
        {
            i++, j++;
            continue;
        }
        return false;
    }
    return freq(ind, s);
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool g = false;
    for (int i = 0; i < n; i++)
    {
        if (can(i, s))
        {
            string req = "abacaba";
            for (int j = 0; j < 7; j++)
            {
                s[i + j] = req[j];
            }
            for (int j = 0; j < n; j++)
            {
                if (s[j] != '?')
                    continue;
                s[j] = 'z';
            }
            g = true;
            break;
        }
    }
    if (g)
        cout << "YES" << endl
             << s << endl;
    else
        cout << "NO" << endl;
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