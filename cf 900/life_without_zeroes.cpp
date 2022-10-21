#include <bits/stdc++.h>
using namespace std;
#define ll long long

int stringtoint(const string &s)
{
    int num = 0;
    int i = 0;
    while (i < s.length())
    {
        if (s[i] == '0')
        {
            i++;
            continue;
        }
        else
        {
            num = num * 10 + s[i] - '0';
        }
        i++;
    }
    return num;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    int o = n + m;
    int n1 = stringtoint(to_string(n));
    int m1 = stringtoint(to_string(m));
    int o1 = stringtoint(to_string(o));
    if (o1 == n1 + m1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}