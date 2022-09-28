#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s, ans = "";
    cin >> s;
    bool got = false;
    vector<int> check;
    bool chgot = true;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'a')
        {
            check.push_back(i);
        }
    }
    char ch;
    for (int i = 0; i < 26; i++)
    {
        if (!chgot)
        {
            break;
        }
        ch = 'a' + i;
        chgot = false;
        // cout << ch << endl;
        for (int j = 0; j < n; j++)
        {
            if (s[j] == ch)
            {
                // cout << s[j] << "  aa" << endl;
                chgot = true;
                break;
            }
        }
        if (!chgot)
        {
            // cout << "ng" << endl;
            got = true;
            ans += ch;
            break;
        }
    }
    chgot = true;
    if (!got)
    {
        // cout << "here" << endl;
        for (int i = 0; i < 26; i++)
        {
            if (!chgot)
            {
                break;
            }
            ch = 'a' + i;
            chgot = true;
            for (int j = 0; j < check.size(); j++)
            {
                if (check[j] + 1 == n)
                {
                    continue;
                }
                if (s[check[j] + 1] != ch)
                {
                    chgot = false;
                    break;
                }
            }
            if (!chgot)
            {
                got = true;
                ans += ch;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}