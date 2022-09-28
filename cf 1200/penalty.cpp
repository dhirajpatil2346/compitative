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
        string s1 = s, s2 = s;

        // case 1 : p1 is scoring
        for (int i = 0; i < s.length(); i++)
        {
            if (i % 2 == 0)
            {
                if (s1[i] == '?')
                {
                    s1[i] = '1';
                }
            }
        }
        int c1 = 10;
        int p1c = 0, p2c = 0, p1m = 5, p2m = 5;
        for (int i = 0; i < 9; i++)
        {
            if (i % 2 == 0)
            {
                p1m--;
                if (s1[i] == '1')
                {
                    p1c++;
                }
            }
            else
            {
                p2m--;
                if (s1[i] == '1')
                {
                    p2c++;
                }
            }
            if (p1c - p2c > p2m)
            {
                c1 = i + 1;
                break;
            }
            else if (p2c - p1c > p1m)
            {
                c1 = i + 1;
                break;
            }
        }

        // case 2 : p2 is scoring
        int c2 = 10;
        for (int i = 0; i < s.length(); i++)
        {
            if (i % 2 == 1)
            {
                if (s2[i] == '?')
                {
                    s2[i] = '1';
                }
            }
        }
        p1c = 0, p2c = 0, p1m = 5, p2m = 5;
        for (int i = 0; i < 9; i++)
        {

            if (i % 2 == 0)
            {
                p1m--;
                if (s2[i] == '1')
                {
                    p1c++;
                }
            }
            else
            {
                p2m--;
                if (s2[i] == '1')
                {
                    p2c++;
                }
            }
            if (p1c - p2c > p2m)
            {
                c2 = i + 1;
                break;
            }
            else if (p2c - p1c > p1m)
            {
                c2 = i + 1;
                break;
            }
        }
        cout << min(c1, c2) << endl;
    }
    return 0;
}