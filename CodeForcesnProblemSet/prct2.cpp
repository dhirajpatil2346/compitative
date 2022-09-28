#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int nl = 0;
    unordered_set<char> us;
    for (int i = 0; i < s.length(); i++)
    {
        us.insert(s[i]);
        if (s[i] == '4' || s[i] == '7')
        {
            nl++;
        }
    }
    // cout<<nl<<endl;
    if (us.size() < 2)
    {
        cout << "NO";
        return 0;
    }
    else if ((us.size() == 2) && (*us.begin() == '4' || *us.begin() == '7') && (*(++us.begin()) == '4' || (*(++us.begin()) == '7')))
    {
        cout <<"YES";
        return 0;
    }

    string m = to_string(nl);
    // cout << m;
    unordered_set<char> su;
    for (int i = 0; i < m.length(); i++)
    {
        if (m[i] == '4' || m[i] == '7')
        {
            // nl++;
            su.insert(m[i]);
        }
    }
    if (!su.empty())
    {
        cout << "YES";
        return 0;
    }
    else
    {
        cout << "NO";
        return 0;
    }
}