#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string del0(string m)
{
    string z = "";
    if (m.size() >= 3 && m[m.size() - 1] == '1' && m[m.size() - 2] == '1')
    {
        m[m.size() - 1] = '$';
        for (int i = 0; i < (int)m.size(); ++i)

            if (m[i] == '0')
            {
                m[i] = '$';
                break;
            }

        for (int i = 0; i < (int)m.size(); i++)

            if (m[i] == '$')
                z += m[i];

        return z;
    }
    else
        return m;
}
int calc(string str)
{
    vector<int> T;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '0')
            T.push_back(i);
    }
    if (T.size() == 1)
        return 1;
    if (T[T.size() - 1] == T[T.size() - 2])
        return 1;
    for (int i = 0; i < T.size() - 2; ++i)
        if (str[i] == '1')
            return 1;
    return 2;
}
void solve()
{
    string s, m = "";
    int t = 0, p = 0;
    cin >> s;
    for (int i = (int)s.size() - 1; i >= 0; --i)

        if (s[i] == '1')
        {
            for (int j = 0; j <= i; j++)
                m += s[j];
            break;
        }
        else
            t++;

    if (t == (int)s.size())
    {
        cout << s << "\n";
        return;
    }
    s = m;
    for (int i = 0; i < (int)s.size(); i++)

        if (s[i == '0'])
            p++;

    if (p == 0)
    {
        cout << s;
        for (int i = 0; i < t; i++)

            putchar('0');

        putchar('\n');
        return;
    }
    if (p % 2)
    {
        int l = INT_MAX, r = INT_MIN;
        for (int i = 0; i < (int)s.size(); i++)
            if (s[i] == '0')
            {
                l = min(l, i);
                r = max(r, i);
            }
        for (int i = l; i <= r; i++)
            if (s[i] == '1')
            {
                for (int j = 0; j < (int)s.size(); j++)
                    if (s[j] == '1')
                        putchar('1');

                for (int i = 0; i < t; i++)
                    putchar('0');
                putchar('\n');
                return;
            }

        if (t >= 2)
        {
            for (int i = 0; i < (int)s.size(); ++i)
                if (s[i] == '1')
                    putchar('1');
            for (int i = 0; i < t - 2; ++i)
                putchar('0');
            putchar('\n');
            return;
        }
        if (t == 1)
        {
            m = "";
            for (int i = (int)s.size() - 1; i >= 0; i--)
                if (s[i] == '0')
                {
                    s[i] = '$';
                    break;
                }
            for (int i = 0; i < (int)s.size(); i++)
                if (s[i] == '$')

                    m += '0';

                else if (s[i] == '1')

                    m += '1';

            s = m;
            cout << del0(s) << endl;
            return;
        }
        if (t == 0)
        {
            int _ = 0;
            m = "";
            for (int i = (int)s.size() - 1; i >= 0; i--)
                if (s[i] == '0')
                {
                    s[i] = '$';
                    _++;
                    if (_ == 2)

                        break;
                }
            for (int i = 0; i < (int)s.size(); i++)
            {
                if (s[i] == '$')
                    m += '0';
                else if (s[i] == '1')
                    m += '1';
            }
            s = m;
            cout << del0(del0(s)) << "\n";
            return;
        }
    }
    int T = 0, L = calc(s);
    m = "";
    for (int i = s.size() - 1; i >= 0; --i)

        if (s[i] == '0')
        {

            T++;
            if (T == L)

                s[i] = '$';
        }

    for (int i = 0; i < (int)s.size(); ++i)

        if (s[i] == '1')

            m += '1';

        else if (s[i] == '$')

            m += '0';

    s = m;
    if (t != 0)
    {
        for (int i = 0; i < (int)s.size(); i++)
            if (s[i] == '1')
                putchar('1');
        for (int i = 0; i < t - 1; i++)
            putchar('0');
        putchar('\n');
        return;
    }
    cout << del0(m) << endl;
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}