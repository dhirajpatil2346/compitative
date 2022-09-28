#include <bits/stdc++.h>
using namespace std;

bool isP(string a, string b)
{
    return ((a[1] == b[0]) && (a[0] == b[1]));
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        int inc;
        cin >> s;
        cin >> inc;
        int n1 = (s[0] - '0') * 10 + (s[1] - '0');
        int n2 = (s[3] - '0') * 10 + (s[4] - '0');
        long long curr = n1 * 60 + n2;
        long long dd = curr;
        // cout<<dd<<"         "<<curr<<endl;
        int f = 0;
        string a = "", b = "";
        int h = curr / 60, m = curr % 60;
        if (h < 10)
        {
            a += '0';
            a += (h + '0');
        }
        else
        {
            a = to_string(h);
        }
        if (m < 10)
        {
            b += '0';
            b += (m + '0');
        }
        else
        {
            b = to_string(m);
        }
        if (isP(a, b))
        {
            f++;
        }
        // cout << a << "  " << b << "     " << curr << endl;
        curr += inc;
        curr%=1440;
        while (curr != dd)
        {
            a = "", b = "";
            h = curr / 60, m = curr % 60;
            h %= 24;
            if (h < 10)
            {
                a += '0';
                a += (h + '0');
            }
            else
            {
                a = to_string(h);
            }
            if (m < 10)
            {
                b += '0';
                b += (m + '0');
            }
            else
            {
                b = to_string(m);
            }
            if (isP(a, b))
            {
                f++;
            }
            // cout << a << "  " << b << "     " << curr << endl;
            curr += inc;
            curr %= 1440;
        }
        cout << f << endl;
    }
    return 0;
}