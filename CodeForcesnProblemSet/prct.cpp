#include <bits/stdc++.h>
using namespace std;
int main()
{
    string n;
    cin >> n;
    unordered_set<char> us;
    if (n.length() > 1)
    {
        for (auto it = n.begin(); it != n.end(); ++it)
        {
            us.insert(*it);
        }
        if ((*us.begin() == '4' || *us.begin() == '7') && ((*(++us.begin()) == '4') || (*(++us.begin()) == '7')))
        {
            cout << "YES";
            return 0;
        }
        int sum = 0;
        for (auto it = n.begin(); it != n.end(); ++it)
        {
            if (*it == '7' || *it == '4')
            {
                sum += *it - 0;
            }
        }
        string s = to_string(sum);
        unordered_set<char> su;
        for (auto it = n.begin(); it != n.end(); ++it)
        {
            su.insert(*it);
        }
        if ((*us.begin() == '4' || *us.begin() == '7') && ((*(++us.begin()) == '4') || (*(++us.begin()) == '7')))
        {
            cout << "YES";
            return 0;
        }
        else
        {
            cout << "NO";
        }
        return 0;
    }
    else
    {
        cout << "NO";
        return 0;
    }
}