#include <bits/stdc++.h>
using namespace std;

int main()
{
    string n;
    cin >> n;
    if (n.length() > 1)
    {
        unordered_set<char> us;
        int nl = 0;
        for (auto it = n.begin(); it != n.end(); ++it)
        {
            us.insert(*it);
            if (*it == '4' || *it == '7')
            {
                nl++;
            }
        }
        if ((*us.begin() == '4' || *us.begin() == '7') && ((*(++us.begin()) == '4') || (*(++us.begin()) == '7')))
        {
            cout << "YES";
            return 0;
        }
        string s;
        s = to_string(nl);
        unordered_set<char> su;
        for (auto it = s.begin(); it != s.end(); ++it)
        {
            su.insert(*it);
        }
        if ((*su.begin() == '4' || *su.begin() == '7') && ((*(++su.begin()) == '4') || (*(++su.begin()) == '7')))
        {
            cout << "YES";
            return 0;
        }
        cout << "NO";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}