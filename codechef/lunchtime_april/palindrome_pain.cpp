/*
if both odd
    -1
if both even
    form 2 combo
if one odd one even
    if odd > 1
        make 2 combo
    else -1
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int odd = 0, even = 0;
        int a, b;
        cin >> a >> b;
        int len = a + b;
        cout << len << endl;
        vector<char> c1(len), c2(len);
        c1[0] = 'a', c1[len - 1] = 'a', c1[1] = 'b', c1[len - 2] = 'b';
        c2[0] = 'b', c2[len - 1] = 'b', c2[1] = 'a', c2[len - 2] = 'a';
        if (a % 2 == 0)
        {
            even = a;
            odd = b;
        }
        else if (b % 2 == 0)
        {
            even = b;
            odd = a;
        }
        if (even == 0 || odd == 1)
        {
            cout << -1 << endl;
        }
        else
        {
            if (a % 2 == 0 && b % 2 == 0)
            {
                for (int i = 0, j = 2; i < a / 2 - 1; i++, j++)
                {
                    c1[j] = 'a';
                }
                for (int i = 0, j = len - 3; i < a / 2 - 1; i++, j--)
                {
                    c1[j] = 'a';
                }
                for (int i = 0, j = 1 + a / 2; i < b-2; i++, j++)
                {
                    c1[j] = 'b';
                }

                for (int i = 0, j = 2; i < a / 2 - 1; i++, j++)
                {
                    c2[j] = 'a';
                }
                for (int i = 0, j = len - 3; i < a / 2 - 1; i++, j--)
                {
                    c2[j] = 'a';
                }
                for (int i = 0, j = 1 + a / 2; i < b-2; i++, j++)
                {
                    c2[j] = 'b';
                }
            }
            else if (a % 2 == 0)
            {
                for (int i = 0, j = 2; i < a / 2 - 1; i++, j++)
                {
                    c1[j] = 'a';
                }
                for (int i = 0, j = len - 3; i < a / 2 - 1; i++, j--)
                {
                    c1[j] = 'a';
                }
                for (int i = 0, j = a / 2 + 1; j < b; i++, j++)
                {
                    c1[j] = 'b';
                }

                for (int i = 0, j = 2; i < a / 2 - 1; i++, j++)
                {
                    c2[j] = 'a';
                }
                for (int i = 0, j = len - 3; i < a / 2 - 1; i++, j--)
                {
                    c2[j] = 'a';
                }
                for (int i = 0, j = a / 2 + 1; j < b; i++, j++)
                {
                    c2[j] = 'b';
                }
                c1[len / 2] = 'b';
                c2[len / 2] = 'b';
            }
            else
            {
                for (int i = 0, j = 2; i < b / 2 - 1; i++, j++)
                {
                    c1[j] = 'b';
                }
                for (int i = 0, j = len - 3; i < b / 2 - 1; i++, j--)
                {
                    c1[j] = 'b';
                }
                for (int i = 0, j = b / 2 + 1; j < b - 2; i++, j++)
                {
                    c1[j] = 'a';
                }

                for (int i = 0, j = 2; i < b / 2 - 1; i++, j++)
                {
                    c2[j] = 'b';
                }
                for (int i = 0, j = len - 3; i < b / 2 - 1; i++, j--)
                {
                    c2[j] = 'b';
                }
                for (int i = 0, j = b / 2 + 1; j < a - 2; i++, j++)
                {
                    c2[j] = 'a';
                }
                c1[len / 2] = 'a';
                c2[len / 2] = 'a';
            }
            for (int i = 0; i < len; i++)
            {
                cout << c1[i];
            }
            cout << endl;
            for (int i = 0; i < len; i++)
            {
                cout << c2[i];
            }
            cout << endl;
        }
    }
    return 0;
}