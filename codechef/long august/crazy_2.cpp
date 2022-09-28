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
        int n = s.length();
        int one = 0, zero = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                one++;
            }
            else
            {
                zero++;
            }
        }
        if (one == 0 || zero <= 1)
        {
            cout << s << endl;
        }
        else
        {
            if (zero == 2)
            {
                // check pos
                int z1 = 0, z2 = 0;
                for (int i = 0; i < n; i++)
                {
                    if (s[i] == '0')
                    {
                        z1 = i;
                        break;
                    }
                }
                for (int i = z1 + 1; i < n; i++)
                {
                    if (s[i] == '0')
                    {
                        z2 = i;
                        break;
                    }
                }
                if (z2 - z1 == 1)
                {
                    cout << s << endl;
                }
                else
                {
                    string ans = "";
                    for (int i = 0; i < n; i++)
                    {
                        if (i == z1 || i == z2)
                        {
                            continue;
                        }
                        else
                        {
                            ans += s[i];
                        }
                    }
                    cout << ans << endl;
                }
            }
            else
            {
                int l = one;

                if (zero % 2)
                {
                    l++;
                    // find zero's position in length l
                    int pos = l - 1;
                    for (int i = l - 1; i >= 0; i--)
                    {
                        if (s[i] == '0')
                        {
                            pos = i;
                            break;
                        }
                    }
                    // count 1s before pos
                    int f1 = 0;
                    for (int i = 0; i < pos; i++)
                    {
                        if (s[i] == '1')
                        {
                            f1++;
                        }
                    }
                    string ans = "";
                    for (int i = 0; i < f1; i++)
                    {
                        ans += '1';
                    }
                    ans += '0';
                    for (int i = f1 + 1; i < l; i++)
                    {
                        ans += '1';
                    }
                    bool found = false;
                    for (int i = ans.length(); i < s.length(); i++)
                    {
                        if (s[i] == '1')
                        {
                            found = true;
                        }
                    }
                    if (!found)
                    {
                        cout << s << endl;
                    }
                    else
                    {
                        cout << ans << endl;
                    }
                }
                else
                {
                    bool found_1 = false;
                    string ans = "";
                    for (int i = 1; i < s.length() - 1; i++)
                    {
                        if (s[i] == '1' && s[i - 1] == '0' && s[i + 1] == '0')
                        {
                            found_1 = true;
                            break;
                        }
                    }

                    if (found_1)
                    {
                        // cout << "found" << endl;
                        for (int i = 0; i < one; i++)
                        {
                            ans += "1";
                        }
                    }
                    else
                    {
                        l += 2;
                        // find zero's position in length l
                        int pos1 = l - 1;
                        int pos2 = l - 1;
                        for (int i = l - 1; i >= 0; i--)
                        {
                            if (s[i] == '0')
                            {
                                pos2 = i;
                                break;
                            }
                        }
                        for (int i = pos2 - 1; i >= 0; i--)
                        {
                            if (s[i] == '0')
                            {
                                pos1 = i;
                                break;
                            }
                        }
                        int f1 = 0, f2 = 0;
                        // calculate 1's before pos1 as f1 and pos2 as f2
                        for (int i = 0; i < pos1; i++)
                        {
                            if (s[i] == '1')
                            {
                                f1++;
                            }
                        }
                        for (int i = pos1 + 1; i < pos2; i++)
                        {
                            if (s[i] == '1')
                            {
                                f2++;
                            }
                        }
                        int k1 = f1, k2 = f2;
                        while (k1--)
                        {
                            ans += '1';
                        }
                        ans += '0';
                        while (k2--)
                        {
                            ans += '1';
                        }
                        ans += '0';
                        int final = l - (2 + f1 + f2);
                        while (final--)
                        {
                            ans += '1';
                        }
                    }
                    bool found = false;
                    for (int i = ans.length(); i < s.length(); i++)
                    {
                        if (s[i] == '1')
                        {
                            found = true;
                        }
                    }
                    if (!found)
                    {
                        cout << s << endl;
                    }
                    else
                    {
                        cout << ans << endl;
                    }
                }
            }
        }
    }
    return 0;
}