#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    bool got = false;
    string s;
    cin >> s;
    string ans = "";
    vector<int> to_check;
    bool chgot;
    char ch;
    chgot = true;
    for (int i = 0; i < 26; i++)
    {
        if (!chgot)
        {
            break;
        }
        if (got)
        {
            break;
        }
        ch = ('a' + i);
        for (int j = 0; j < n; j++)
        {
            if (s[j] != ch)
            {
                if (s[j] == 'a')
                {
                    to_check.push_back(j);
                }
                chgot = false;
            }
        }
    }
    if (!chgot)
    {
        ans += ch;
        got = true;
    }
    else
    {
        ans += 'a';
    }
    while (!got)
    {
        chgot == false;
        vector<int> new_check;
        for (auto &val : to_check)
        {
            cout << val << " ";
        }
        cout << endl;
        for (int i = 0; i < 26; i++)
        {
            if (!chgot)
            {
                false;
            }
            if (got)
            {
                break;
            }
            ch = ('a' + i);
            bool chgot = false;
            for (int j = 0; j < to_check.size(); j++)
            {
                if (chgot)
                {
                    break;
                }
                if (s[j] == ch)
                {
                    if (to_check[j] + 1 == n)
                    {
                        continue;
                    }
                    if (s[to_check[j] + 1] == 'a')
                    {
                        new_check.push_back(j);
                    }
                    chgot = true;
                }
            }
            if (!chgot)
            {
                ans += ch;
                got = true;
            }
            else
            {
                ans += 'a';
            }
            to_check = new_check;
        }
    }
    cout << ans << endl;
    return 0;
}