#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    unordered_set<char> s1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ',' && s[i] != '{' && s[i] != '}' && s[i] != ' ')
        {
            s1.insert(s[i]);
        }
    }
cout<<s1.size();
    return 0;
}