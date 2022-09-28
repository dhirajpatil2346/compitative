#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int value = 0;
        for (auto &val : s)
        {
            if (val == '1')
            {
                value++;
            }
        }
        if (value == 0)
        {
            cout << n * k << endl;
        }
        else if (value == n)
        {
            if ((n * k) % 2)
            {
                cout << 0 << endl;
            }
            else
            {
                cout << 1 << endl;
            }
        }
        else
        {
            if (k % 2)
            {
                int pre = 0, suff = 0;
                int a = 0;
                vector<int> prefix(s.length()), suffix(s.length());
                for (int i = 0; i < s.length(); i++)
                {
                    if (s[i] == '1')
                    {
                        pre++;
                    }
                    prefix[i] = pre;
                }
                for (int i = s.length() - 1; i >= 0; i--)
                {
                    suffix[i] = suff;
                    if (s[i] == '1')
                    {
                        suff++;
                    }
                }
                for (int i = 0; i < s.length(); i++)
                {
                    if (prefix[i] == suffix[i])
                    {
                        a++;
                    }
                }
                cout << a << endl;
            }
            else
            {
                s += s;
                int pre = 0, suff = 0;
                int a = 0;
                vector<int> prefix(s.length()), suffix(s.length());
                for (int i = 0; i < s.length(); i++)
                {
                    if (s[i] == '1')
                    {
                        pre++;
                    }
                    prefix[i] = pre;
                }
                for (int i = s.length() - 1; i >= 0; i--)
                {
                    suffix[i] = suff;
                    if (s[i] == '1')
                    {
                        suff++;
                    }
                }
                for (int i = 0; i < s.length(); i++)
                {
                    if (prefix[i] == suffix[i])
                    {
                        a++;
                    }
                }
                cout << a << endl;
            }
        }
    }
    return 0;
}