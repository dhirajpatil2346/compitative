#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<char, int> m1, m2;
    string s, k;
    getline(cin >> ws, s);
    getline(cin >> ws, k);
    int l1 = s.length(), l2 = k.length();
    for (int i = 0; i < l1; i++)
    {
        m1[s[i]]++;
    }
    for (int i = 0; i < l2; i++)
    {
        m2[k[i]]++;
    }
    for (auto it = m2.begin(); it != m2.end(); it++)
    {
        if (it->first != ' ')
        {
            if (m1[it->first] < it->second)
            {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}